#ifndef COIN_MODEL_H
#define COIN_MODEL_H

#include "obstacle.h"

class CoinModel : public Obstacle
{
public:
    CoinModel(int relat_x, int relat_y, int width, int height);
    ~CoinModel();

    void action(Player &player);
    void update();
    bool checkCollision(Movable &m) const;
};

#endif // COIN_MODEL_H
