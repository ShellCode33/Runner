#include "game_view.h"
#include "window.h"

using namespace std;
using namespace sf;

GameView::GameView(WindowRunner &window, Game &model) : window(window), game(model), player_view(PLAYER_IMG, game.player), fire(20.0), fire2(20.0)
{
    int i;
    for(i = 0; i < CHUNK_PRELOAD; i++)
    {
        Chunk *c = new Chunk();
        c->setPosition(i*CHUNK_WIDTH);
        chunks.push_back(c);
    }

    fire_texture.loadFromFile(FIRE_IMG);
    fire.setTexture(fire_texture);

    int j;
    for(i = 0; i < 12; i++)
        for(j = 0; j < 4; j++)
            fire.addClip(IntRect(j*600, i*337, 600, 337));

    fire.setPosition(337, 0);
    fire.setRotation(90);
    fire2 = fire;
    fire2.setPosition(337, 500);
    fire2.setRotation(90);
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
    target.draw(fire, states);
    target.draw(fire2, states);
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
    fire.update(); //On met l'animation du feu à jour
    fire2.update();

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
            c->pos_x -= game.player.getVelocity().first;

        c->update();
    }

    game.player.setMoveBackground(false);
}
