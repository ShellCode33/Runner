#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "const.h"

enum Direction
{
  LEFT,
  RIGHT
};

class Movable
{
public:
    Movable();
    ~Movable();
    void setPosition(sf::Vector2f p);
    void setVelocity(sf::Vector2f v);
    //bool inAir(int ground, int height_object) const;
    void run(sf::Vector2f v, const float move_speed, const float acceleration, const int framerate);
    void jump(sf::Vector2f v, const float jump_speed, const float gravity, const int framerate, sf::Vector2f p, const int ground, const int height_object);

private:
    sf::Vector2f pos;
    sf::Vector2f velocity;
    Direction direction;

};

#endif // MOVABLE_H
