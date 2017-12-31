/*!
 * \file coin.h
 * \class Coin
 * \brief Bonus permettant d'augmenter son score
 * \author J3ry
 */

#ifndef COIN_H
#define COIN_H

#include "coin_model.h"
#include "coin_view.h"
#include "audio.h"
#include <iostream>

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
