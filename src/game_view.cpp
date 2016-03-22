#include "game_view.h"
#include "window.h"

using namespace std;
using namespace sf;

GameView::GameView(WindowRunner &window, Game &model) : window(window), game(model), player_view(PLAYER_IMG, game.player)
{
    int i;
    for(i = 0; i < CHUNK_PRELOAD; i++)
    {
        Chunk *c = new Chunk();
        c->setPosition(i*CHUNK_WIDTH);
        chunks.push_back(c);
    }
}

GameView::~GameView()
{
    for(Chunk *c : chunks)
        delete c;
}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    for(const Chunk *c : chunks)
        target.draw(*c);

    target.draw(player_view, states);
}

void GameView::processEvent(Event &event)
{
    if(this->window.getState() == SURVIVAL || this->window.getState() == CAMPAIGN)
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->window.setState(MENU);

        player_view.processEvents(window, event);
    }
}

void GameView::update()
{
    this->player_view.update(); //On met à jouer l'affichage du joueur

    bool need_move_background = game.player.needMoveBackground();

    //On vérifie que le 1er chunk est visible, si ce n'est pas le cas on le supprime pour un ré-allouer un nouveau
    if((*chunks.begin())->pos_x + CHUNK_WIDTH < 0)
    {
        delete *chunks.begin();
        chunks.pop_front();
        Chunk *c = new Chunk();
        c->setPosition((*chunks.rbegin())->pos_x + CHUNK_WIDTH); //On met le nouveau chunk à coté du dernier dans la liste
        chunks.push_back(c);
    }

    for(Chunk *c : chunks)
    {
        if(need_move_background)
        //c.pos_x -= game.player.getVelocity().first;
            c->pos_x -= 20;

        c->update();
    }

    game.player.setMoveBackground(false);
}
