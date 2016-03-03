#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "movable.h"
#include "player.h"

class PlayerView : public sf::Drawable, Movable
{
public:
    PlayerView();
    ~PlayerView();

private:
    Player player; //Player model


};

#endif // PLAYERVIEW_H
