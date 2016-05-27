/*!
 * \file magnet_model.h
 * \class MagnetModel
 * \brief Partie modèle du bonus Magnet
 * \author Clément
 */

#ifndef MAGNET_MODEL_H
#define MAGNET_MODEL_H

#include "obstacle.h"
#include "effect.h"

class MagnetModel : public Obstacle
{
public:
    MagnetModel(int relat_x, int relat_y, int width, int height);
    ~MagnetModel() = default;
    void start(PlayerModel& player);
    void stop(PlayerModel& player);
    virtual void update();
    virtual bool checkCollision(Movable &m) const;
    virtual void action(GameModel &game);
    bool isTaken() const;


private:
    bool taken;

};

#endif // MAGNET_MODEL_H
