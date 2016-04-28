#ifndef COIN_VIEW_H
#define COIN_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include "coin_model.h"
#include "animation.h"
#include "movable.h"
#include <algorithm>
#include <utility>

class CoinView : public Animation
{
public:
    CoinView(CoinModel &model);
    ~CoinView();
    void update();

private:
    sf::Texture coin_texture;
    CoinModel& model;
};

#endif // COIN_VIEW_H
