#include "game_model.h"
#include "window.h"

using namespace std;

GameModel::GameModel() : score(0)
{
    this->game_begin = chrono::system_clock::now();
}

GameModel::~GameModel()
{

}

void GameModel::update()
{
    auto diff = chrono::system_clock::now() - this->game_begin;
    auto msec = chrono::duration_cast<chrono::milliseconds>(diff);

    this->score = msec.count() / 100;
}

unsigned long GameModel::getScore() const
{
    return this->score;
}
