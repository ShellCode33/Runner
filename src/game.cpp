#include "game.h"

Game::Game(Config *config, WindowRunner *window)
{
    this->config = config;
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
