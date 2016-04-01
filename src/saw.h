/*!
 * \file saw.h
 * \brief Obstacle scie circulaire
 * \author Clément
 *
 */

#ifndef SAW_H
#define SAW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include <algorithm>
#include <utility>

class Saw : public Obstacle
{
public:
    Saw();
    ~Saw();
    void update();
    virtual bool checkCollision(Player &m) const override;
    void action(Player &player);

private:
    sf::Texture texture;

};

#endif // SAW_H
