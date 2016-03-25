#include "bonus.h"

using namespace std;

Bonus::Bonus(int ms, int x, int y) : Animation(ms), relat_x(x), relat_y(y)
{

}

Bonus::~Bonus()
{

}

void Bonus::setPositionRelat(const int x, const int y)
{
    this->relat_x = x;
    this->relat_y = y;
}

std::pair<int, int> Bonus::getPosition() const
{
    return make_pair(this->relat_x, this->relat_y);
}

void Bonus::update()
{

}

bool Bonus::checkCollision(Movable &m)
{
    //TODO: collision entre bonus generique et movable à overrride suivant obstacle
    return false;
}


