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
    return this->pos;
}

void Movable::setPos(const std::pair<float, float> &value)
{
    this->pos = value;
}

int Movable::getX() const
{
    return this->pos.first;
}

int Movable::getY() const
{
    return this->pos.second;
}

int Movable::getHeight() const
{
    return this->height;
}

void Movable::setHeight(int value)
{
    this->height = value;
}

int Movable::getWidth() const
{
    return this->width;
}

void Movable::setWidth(int value)
{
    this->width = value;
}
