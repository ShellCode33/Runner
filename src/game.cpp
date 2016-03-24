#include "game.h"

Game::Game(WindowRunner &window) : game_view(window, game_model, player)
{
    srand(time(NULL));
}

Game::~Game()
{

}

void Game::update()
{
    this->game_model.update();
    this->game_view.update();
    this->player.update();


    for(Chunk* c : this->game_view.getVisibleChunks())
        for(Obstacle* o : c->getObstacles())
            if(o->checkCollision(*player.getModel()))
                o->action();
}

GameView* Game::getView()
{
    return &this->game_view;
}
