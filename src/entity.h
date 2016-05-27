/*!
 * \file entity.h
 * \class Entity
 * \brief classe abstraite qui permet de regrouper certains objets qui devront apparaitre partout sur l'écran (cf: game_view)
 * \author Clément
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "movable.h"

class Entity
{
public:
    Entity() = default;
    virtual ~Entity() = default;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
    virtual void action(Player &player) = 0;
    virtual bool checkCollision(Movable &m) const = 0;

};

#endif
