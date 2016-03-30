#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "utils.h"
#include <chrono>

class GameModel
{
private:
    unsigned long score;
    std::chrono::high_resolution_clock::time_point game_begin;
    std::chrono::high_resolution_clock::time_point timer;
    int fire_offset; /*!< correspond à l'avancement du feu dans la partie */
    int fire_speed; /*!< Nombre de pixel d'avancement du feu */
    int time_per_move; /*!< Vitesse d'approche du feu, évolue avec le temps */


public:
    GameModel();
    ~GameModel();

    void update();
    unsigned long getScore() const;
    int getFireOffset() const;
};

#endif // GAMEMODEL_H
