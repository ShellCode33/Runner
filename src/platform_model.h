/*!
 * \file platform_model.h
 * \class PlatformModel
 * \brief Partie modèle de l'obstacle Platform
 * \author Jérémie
 *
 */

#ifndef PLATFORM_MODEL_H
#define PLATFORM_MODEL_H

#include "obstacle.h"
#include "player.h"
#include "collision.h"

class PlatformModel : public Obstacle
{
public:
    PlatformModel(int relat_x, int relat_y, int width, int height);
    ~PlatformModel();

    bool checkCollision(Movable &m) const;
    void action(GameModel &game);
    void update();

};

#endif //PLATFORM_MODEL_H
