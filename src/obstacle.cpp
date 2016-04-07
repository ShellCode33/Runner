#include "obstacle.h"

using namespace std;

Obstacle::Obstacle(int relat_x, int relat_y, int width, int height) : relat_x(relat_x), relat_y(relat_y), width(width), height(height)
{

}

Obstacle::~Obstacle()
{

}

void Obstacle::setPositionRelat(const int x, const int y)
{
    this->relat_x = x;
    this->relat_y = y;
}

pair<int, int> Obstacle::getRelatPosition() const
{
    return make_pair(this->relat_x, this->relat_y);
}

pair<int, int> Obstacle::getSize() const
{
    return make_pair(this->width, this->height);
}

pair<int, int> Obstacle::getAbsolutePos() const
{
    return this->absolute_pos;
}

void Obstacle::setAbsolutePos(const pair<int, int> &value)
{
    this->absolute_pos = value;
}
