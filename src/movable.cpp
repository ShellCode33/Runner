#include "movable.h"

Movable::Movable()
{

}

Movable::~Movable()
{

}

void Movable::setPosition(int x, int y)
{
    this->pos_x = x;
    this->pos_y = y;
}

void Movable::move(int x, int y)
{
    setPosition(this->pos_x + x, this->pos_y + y);
}
