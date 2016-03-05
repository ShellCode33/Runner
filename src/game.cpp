#include "game.h"
#include "window.h"

Game::Game() : config("config"), speed(1.f)
{
    this->config.readConfig();
}

Game::~Game()
{

}
