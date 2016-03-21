#include "movable.h"

using namespace sf;

Movable::Movable()
{
    setPos({0, 0});
}

Movable::~Movable()
{

}

std::pair<float, float> Movable::getPos() const
{
    return pos;
}

void Movable::setPos(const std::pair<float, float> &value)
{
    pos = value;
}

int Movable::getX() const
{
    return pos.first;
}

int Movable::getY() const
{
    return pos.second;
}
