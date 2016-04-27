#include "game_model.h"
#include "window.h"

using namespace std;

GameModel::GameModel(Player &player, list<Chunk *> &chunks, std::list<Entity *> &entities) : score(0), fire_offset(0), fire_speed(3), time_per_move(30), timer(time_per_move), player(player), chunks(chunks)
{
    Chunk *c = new Chunk(0);
    this->chunks.push_back(c);

    c = new Chunk(CHUNK_WIDTH);
    this->chunks.push_back(c);

    int i;
    for(i = 2; i < CHUNK_PRELOAD; i++)
    {
        //c = randomChunk();
        c = new ChunkSpecial(i * CHUNK_WIDTH, player, entities);
        this->chunks.push_back(c);
    }

    this->game_begin.begin();
    this->timer.begin();
}

GameModel::~GameModel()
{

}

void GameModel::update()
{
    this->score = this->game_begin.getDuration() / 100;

    if(this->timer.isFinish())
    {
        this->fire_offset += this->fire_speed;
        this->timer.reset();
    }

    bool need_move_background = this->player.needMoveBackground();

    //On vérifie que le 1er chunk est visible, si ce n'est pas le cas on le supprime pour un ré-allouer un nouveau
    if((*this->chunks.begin())->getModel()->pos_x + CHUNK_WIDTH < 0)
    {
        list<ChunkSpecial*> draw_later;
        delete *this->chunks.begin();
        this->chunks.pop_front();
        Chunk *c = randomChunk((*this->chunks.rbegin())->getModel()->pos_x + CHUNK_WIDTH);//On met le nouveau chunk à coté du dernier dans la liste
        this->chunks.push_back(c);
    }

    for(Chunk *c : this->chunks)
    {
        if(need_move_background)
            c->getModel()->pos_x -= this->player.getBackgroundShift();

        c->update();
    }

    this->player.setMoveBackground(false);
}

unsigned long GameModel::getScore() const
{
    return this->score;
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

Chunk* GameModel::randomChunk(int pos_x_default) const
{
    switch(rand()%2)
    {
        case 1: return new ChunkSaw(pos_x_default);
        default: return new Chunk(pos_x_default);
    }
}
