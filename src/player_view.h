#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "movable.h"
#include "player.h"

class PlayerView : public sf::Drawable
{
public:
    PlayerView();
    ~PlayerView();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    Player player; //Player model


};

#endif // PLAYERVIEW_H
