#ifndef COIN_H
#define COIN_H

#include "coin_model.h"
#include "coin_view.h"

class Coin
{
public:
    Coin(int relat_x, int relat_y, int width, int height);
    ~Coin();

    CoinModel *getModel();
    CoinView *getView();

    void update();

private:
    CoinModel model;
    CoinView view;    
};

#endif // COIN_H
