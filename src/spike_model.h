/*!
 * \file spike_model.h
 * \class SpikeModel
 * \brief Modèle des pics
 * \author ShellCode
 */

#ifndef SPIKE_MODEL_H
#define SPIKE_MODEL_H

#include "obstacle.h"

class SpikeModel : public Obstacle
{
public:
    SpikeModel(int relat_x, int relat_y, int width, int height);
    ~SpikeModel();
    void update();
    bool checkCollision(Movable &m) const;
    void action(GameModel &game);

private:

};

#endif
