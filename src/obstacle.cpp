#include "obstacle.h"

using namespace std;

Obstacle::Obstacle(int relat_x, int relat_y) : relat_x(relat_x), relat_y(relat_y)
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

std::pair<int, int> Obstacle::getPosition() const
{
    return make_pair(this->relat_x, this->relat_y);
}

void Obstacle::update()
{

}

bool Obstacle::checkCollision(Movable &m)
{
    if((m.getX() <= this->getLocalBounds().left + this->getLocalBounds().width)
        && (m.getX() + m.getWidth() >= this->getLocalBounds().left)
        && (m.getY() <= this->getLocalBounds().top + this->getLocalBounds().height)
        && (m.getY() + m.getHeight() >= this->getLocalBounds().top))
        return true;

    return false;
}

void Obstacle::action()
{
    Utils::log("Action de collision");
}
