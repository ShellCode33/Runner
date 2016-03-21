#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "const.h"

class Movable
{
public:
    Movable();
    ~Movable();
    std::pair<float, float> getPos() const;
    void setPos(const std::pair<float, float> &value);
    int getX() const;
    int getY() const;

protected:
    std::pair<float, float> pos;

};

#endif // MOVABLE_H
