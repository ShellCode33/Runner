#ifndef COIN_H
#define COIN_H

#include "coin_model.h"
#include "coin_view.h"

class Coin
{
public:
    Coin(int relat_x, int relat_y, int width, int height);
    ~Coin();

private:
    CoinView view;
    CoinModel model;
};

#endif // COIN_H
