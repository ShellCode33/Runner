#include "movable.h"

using namespace sf;

Movable::Movable() : x(0), y(0)
{

}

Movable::~Movable()
{

}

void Movable::move(const int x, const int y)
{
    this->x += x;
    this->y += y;
}

void Movable::setPos(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

int Movable::getX() const
{
    return x;
}

int Movable::getY() const
{
    return y;
}
