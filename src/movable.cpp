#include "movable.h"

using namespace std;
using namespace sf;

Movable::Movable(int x, int y, int w, int h) : pos(make_pair(x, y)), width(w), height(h)
{

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

int Movable::getHeight() const
{
    return height;
}

void Movable::setHeight(int value)
{
    height = value;
}

int Movable::getWidth() const
{
    return width;
}

void Movable::setWidth(int value)
{
    width = value;
}
