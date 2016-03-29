#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "utils.h"
#include <chrono>

class GameModel
{
private:
    unsigned long score;
    std::chrono::high_resolution_clock::time_point game_begin;


public:
    GameModel();
    ~GameModel();

    void update();
    unsigned long getScore() const;
};

#endif // GAMEMODEL_H
