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
    void move(const int x, const int y);
    void setPos(const int x, const int y);
    int getX() const;
    int getY() const;

private:
    int x;
    int y;

};

#endif // MOVABLE_H
