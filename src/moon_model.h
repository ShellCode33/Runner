#ifndef MOON_MODEL_H
#define MOON_MODEL_H

#include "obstacle.h"

class MoonModel : public Obstacle
{
public:
    MoonModel(int relat_x, int relat_y, int width, int height);
    ~MoonModel();

    void update();
    bool checkCollision(Movable &m) const;
    void action(GameModel &game);

    bool isTaken() const;

private:
    bool taken;

};

#endif //MOON_MODEL_H
