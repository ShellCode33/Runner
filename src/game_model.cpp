#include "game_model.h"
#include "window.h"

using namespace std;

GameModel::GameModel(Player &player, list<Chunk *> &chunks, list<Entity *> &entities) : score(0), bonus_score(0), fire_offset(0), fire_speed(8), time_per_move(30), timer(time_per_move), difficulty_timer(3000), player(player), pseudo("Unknown"), chunks(chunks), entities(entities), police(nullptr)
{
    Chunk *c = new Chunk(0, player);
    this->chunks.push_back(c);

    c = new Chunk(CHUNK_WIDTH, player);
    this->chunks.push_back(c);

    int i;
    for(i = 2; i < CHUNK_PRELOAD; i++)
    {
        c = randomChunk(i * CHUNK_WIDTH);
        this->chunks.push_back(c);
    }

    this->game_begin.begin();
    this->timer.begin();
    this->difficulty_timer.begin();
}

GameModel::~GameModel()
{

}

void GameModel::update()
{
    this->score = this->game_begin.getDuration() / 10;

    if(this->timer.isFinish())
    {
        this->fire_offset += this->fire_speed;
        this->timer.reset();
    }

    if(this->fire_speed < MAX_FIRE_DIFFICULTY && this->difficulty_timer.isFinish())
    {
        Utils::log("increase difficulty");
        this->fire_speed++;
        this->difficulty_timer.reset();
    }

    bool need_move_background = this->player.needMoveBackground();

    //On vérifie que le 1er chunk est visible, si ce n'est pas le cas on le supprime pour un ré-allouer un nouveau
    if((*this->chunks.begin())->getModel()->pos_x + CHUNK_WIDTH < 0)
    {
        delete *this->chunks.begin();
        this->chunks.pop_front();

        if(this->chunks.size() <= CHUNK_PRELOAD)
        {
            if(this->police == nullptr && !(rand() % 6)) //La police arrive 1 fois sur 6
            {
                cout << "POLICE IS COMING" << endl;
                this->police = new Police();
                this->entities.push_back(this->police);

                int i;
                for(i = 0; i < 3; i++) // On prévoit 3 chunks vides (potentiellement avec des pièces) pour laisser passer la police
                {
                    Chunk *c = new Chunk((*this->chunks.rbegin())->getModel()->pos_x + CHUNK_WIDTH, this->player);
                    this->chunks.push_back(c);
                }

                this->police->getModel()->setPosition(make_pair((*this->chunks.rbegin())->getModel()->pos_x + CHUNK_WIDTH*2, this->police->getModel()->getY()));
            }

            else
            {
                Chunk *c = randomChunk((*this->chunks.rbegin())->getModel()->pos_x + CHUNK_WIDTH);//On met le nouveau chunk à coté du dernier dans la liste
                this->chunks.push_back(c);
            }
        }
    }

    for(Chunk *c : this->chunks)
    {
        if(need_move_background)
            c->getModel()->pos_x -= this->player.getBackgroundShift();

        c->update();
    }

    this->player.setMoveBackground(false);

    if(this->police != nullptr)
    {
        this->police->update();

        if(need_move_background)
            this->police->getModel()->setPosition(make_pair(this->police->getModel()->getX() - this->player.getBackgroundShift(), this->police->getModel()->getY()));

        if(this->police->getModel()->getX() + this->police->getModel()->getWidth() < 0)
        {
            this->entities.remove(this->police);
            delete this->police;
            this->police = nullptr;
            cout << "Police is gone" << endl;
        }
    }
}

unsigned long GameModel::getScore() const
{
    return this->score + this->bonus_score;
}

int GameModel::getFireOffset() const
{
    return this->fire_offset;
}

void GameModel::setFireOffset(int value)
{
    if(this->fire_offset > MIN_FIRE_POS)
        this->fire_offset = value;
}

list<Chunk *> GameModel::getVisibleChunks() const
{
    std::list<Chunk *> visible_chunks;
    std::list<Chunk *>::const_iterator it = this->chunks.begin();

    int i;
    for(i = 0; i < 4 && it != this->chunks.end(); i++, ++it)
        visible_chunks.push_back(*it);

    return visible_chunks;
}

std::string GameModel::getPseudo() const
{
    return this->pseudo;
}

void GameModel::setPseudo(const std::string &value)
{
    this->pseudo = value;
}


Player &GameModel::getPlayer() const
{
    return player;
}

Chunk* GameModel::randomChunk(int pos_x_default) const
{
    switch(rand()%4)
    {
        case 1: return new ChunkSaw(pos_x_default, this->player);
        case 2: return new ChunkSpecial(pos_x_default, this->player, this->entities);
        case 3: return new ChunkSpike(pos_x_default, this->player);
        default:
            Chunk *c = new Chunk(pos_x_default, this->player);
            c->spawnBonusRandom();
            return c;
    }
}

Police *GameModel::getPolice() const
{
    return this->police;
}

void GameModel::addBonusScore(unsigned long value)
{
    this->bonus_score += value;
}
