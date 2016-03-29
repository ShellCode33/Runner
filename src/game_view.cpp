#include "game_view.h"
#include "window.h"

using namespace std;
using namespace sf;

GameView::GameView(WindowRunner &window, GameModel &model, Player &player) : window(window), game_model(model), fire(20.0), fire2(20.0), player(player)
{
    int i;
    for(i = 0; i < CHUNK_PRELOAD; i++)
    {
        Chunk *c = new Chunk();
        c->setPosition(i*CHUNK_WIDTH);
        this->chunks.push_back(c);
    }

    assert(this->fire_texture.loadFromFile(FIRE_ANIM));
    this->fire.setTexture(fire_texture);

    int j;
    for(i = 0; i < 12; i++)
        for(j = 0; j < 4; j++)
            this->fire.addClip(IntRect(j*600, i*337, 600, 337));

    this->fire.setPosition(337, 0);
    this->fire.setRotation(90);
    this->fire2 = this->fire;
    this->fire2.setPosition(337, 500);
    this->fire2.setRotation(90);
}

GameView::~GameView()
{
    for(Chunk *c : this->chunks)
        delete c;
}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    for(const Chunk *c : this->chunks)
        target.draw(*c);

    target.draw(*this->player.getView(), states);
    target.draw(this->fire, states);
    target.draw(this->fire2, states);
}

void GameView::processEvent(Event &event)
{
    if(this->window.getState() == SURVIVAL || this->window.getState() == CAMPAIGN)
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->window.setState(MENU);

        this->player.getView()->processEvents(this->window, event);
    }
}

void GameView::update()
{
    this->player.getView()->update(); //On met à jouer l'affichage du joueur
    this->fire.update(); //On met l'animation du feu à jour
    this->fire2.update();

    bool need_move_background = this->player.needMoveBackground();

    //On vérifie que le 1er chunk est visible, si ce n'est pas le cas on le supprime pour un ré-allouer un nouveau
    if((*this->chunks.begin())->pos_x + CHUNK_WIDTH < 0)
    {
        delete *this->chunks.begin();
        this->chunks.pop_front();
        Chunk *c;

        if(rand()%2)
            c = new ChunkSaw();

        else
            c = new Chunk();

        c->setPosition((*this->chunks.rbegin())->pos_x + CHUNK_WIDTH); //On met le nouveau chunk à coté du dernier dans la liste
        this->chunks.push_back(c);
    }

    for(Chunk *c : this->chunks)
    {
        if(need_move_background)
            c->pos_x -= this->player.getBackgroundShift();

        c->update();
    }

    this->player.setMoveBackground(false);
}

std::list<Chunk *> GameView::getChunks() const
{
    return chunks;
}

std::list<Chunk *> GameView::getVisibleChunks() const
{
    std::list<Chunk *> visible_chunks;
    std::list<Chunk *>::const_iterator it = chunks.begin();

    int i;
    for(i = 0; i < NB_CHUNK+1 && it != chunks.end(); i++, ++it)
        visible_chunks.push_back(*it);

    return visible_chunks;
}
