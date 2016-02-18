#include "game.h"
//steak
Game::Game(WindowRunner *window)
{
    this->window = window;
    this->player = new Player();
}

Game::~Game()
{
    delete this->player;
}


void Game::run()
{

}
