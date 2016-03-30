#include "game_model.h"
#include "window.h"

using namespace std;

GameModel::GameModel() : score(0), fire_offset(0), fire_speed(3), time_per_move(30)
{
    this->game_begin = chrono::system_clock::now();
    this->timer = chrono::system_clock::now();
}

GameModel::~GameModel()
{

}

void GameModel::update()
{
    auto diff = chrono::system_clock::now() - this->game_begin;
    auto msec = chrono::duration_cast<chrono::milliseconds>(diff);
    this->score = msec.count() / 100;


    auto diff2 = chrono::system_clock::now() - this->timer;
    auto msec2 = chrono::duration_cast<chrono::milliseconds>(diff2);

    if(msec2.count() > this->time_per_move)
    {
        this->fire_offset += this->fire_speed;
        this->timer = chrono::system_clock::now();
    }
}

unsigned long GameModel::getScore() const
{
    return this->score;
}

int GameModel::getFireOffset() const
{
    return fire_offset;
}
