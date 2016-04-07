#ifndef SAW_MODEL_H
#define SAW_MODEL_H

#include "obstacle.h"

class SawModel : public Obstacle
{
public:
    SawModel(int relat_x, int relat_y, int width, int height);
    ~SawModel();

    void action(Player &player);
    bool checkCollision(Movable &m) const;
    void update();

private:


};

#endif // SAW_MODEL_H
