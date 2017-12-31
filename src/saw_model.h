/*!
 * \file saw_model.h
 * \class SawModel
 * \brief Partie modèle de l'obstacle scie circulaire
 * \author ShellCode
 */

#ifndef SAW_MODEL_H
#define SAW_MODEL_H

#include "obstacle.h"

class SawModel : public Obstacle
{
public:
    SawModel(int relat_x, int relat_y, int width, int height);
    ~SawModel();

    void action(GameModel &game);
    bool checkCollision(Movable &m) const;
    void update();

private:


};

#endif // SAW_MODEL_H
