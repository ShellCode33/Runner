#include "obstacle.h"

using namespace std;

Obstacle::Obstacle(int relat_x, int relat_y, int width, int height) : Movable(relat_x, relat_y, width, height), relat_x(relat_x), relat_y(relat_y)
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
