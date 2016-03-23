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

class Saw : public Obstacle
{
public:
    Saw();
    ~Saw();
    virtual void update();

private:
    sf::Texture texture;

};

#endif // SAW_H
