#ifndef MOVABLE_H
#define MOVABLE_H

#include <SFML/Graphics.hpp>
#include <iostream>

#include "const.h"

class Movable
{
public:
    Movable(int x = 0, int y = 0, int w = 0, int h = 0);
    ~Movable();


    std::pair<float, float> getPos() const;
    void setPos(const std::pair<float, float> &value);

    int getX() const;
    int getY() const;

    int getHeight() const;
    void setHeight(int value);

    int getWidth() const;
    void setWidth(int value);

protected:
    std::pair<float, float> pos;
    int width;
    int height;

};

#endif // MOVABLE_H
