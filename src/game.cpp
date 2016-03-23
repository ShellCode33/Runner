#include "game.h"

Game::Game(WindowRunner &window) : game_view(window, game_model, player)
{

}

Game::~Game()
{

}

void Game::update()
{
    this->game_model.update();
    this->game_view.update();
    this->player.update();
}

GameView* Game::getView()
{
    return &this->game_view;
}
