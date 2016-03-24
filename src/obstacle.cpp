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
    //On utilise Sprite:: pour récupérer la position absolue de l'image
    int obst_w = this->getLocalBounds().width;
    int obst_h = this->getLocalBounds().height;

    //On enlève la taille car l'origine est au centre
    int obst_x = this->Sprite::getPosition().x - obst_w / 2;
    int obst_y = this->Sprite::getPosition().y - obst_h / 2;

    if((m.getX() <= obst_x + obst_w)
        && (m.getX() + m.getWidth() >= obst_x)
        && (m.getY() <= obst_y + obst_h)
        && (m.getY() + m.getHeight() >= obst_y))
        m.setPos(make_pair(500, 500));
        //return true;

    return false;
}

void Obstacle::action()
{

}
