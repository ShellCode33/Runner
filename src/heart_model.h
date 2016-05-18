#ifndef HEART_MODEL_H
#define HEART_MODEL_H

#include "obstacle.h"

class HeartModel : public Obstacle
{
public:
    HeartModel(int relat_x, int relat_y, int width, int height);
    ~HeartModel();
    void update();
    bool checkCollision(Movable &m) const;
    void action(GameModel &game);
    bool isTaken() const;

private:
    bool taken;

};


#endif
