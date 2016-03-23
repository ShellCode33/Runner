#include "game.h"

Game::Game(WindowRunner &window) : game_view(window, game_model, player)
{

}

Game::~Game()
{

}

void Game::update()
{
    game_model.update();
    game_view.update();
    player.update();
}

GameView* Game::getView()
{
    return &game_view;
}
