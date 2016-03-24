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
    int x_obst = this->getLocalBounds().left;
    int y_obst = this->getLocalBounds().top;
    int w_obst = this->getLocalBounds().width;
    int h_obst = this->getLocalBounds().height;

    //TODO : collision entre le joueur et l'obstacle

    return false;
}

void Obstacle::action()
{
    Utils::log("Action de collision");
}
