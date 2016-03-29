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

bool Obstacle::checkCollision(Player &player) const
{
    PlayerModel m =  *player.getModel();
    int obst_w = this->getLocalBounds().width;
    int obst_h = this->getLocalBounds().height;

    //On enlève la taille car l'origine est au centre
    //On utilise Sprite:: pour récupérer la position absolue de l'image
    int obst_x = this->Sprite::getPosition().x - obst_w / 2;
    int obst_y = this->Sprite::getPosition().y - obst_h / 2;

    if((m.getX() <= obst_x + obst_w)
        && (m.getX() + m.getWidth() >= obst_x)
        && (m.getY() <= obst_y + obst_h)
        && (m.getY() + m.getHeight() >= obst_y))
        return true;

    return false;
}

void Obstacle::action(Player &player)
{

}

bool Obstacle::pointIntersectRect(Point p, Rect r) const
{
    return(p.x < r.br.x && p.x > r.tl.x && p.y < r.br.y && p.y > r.tl.y);
}

bool Obstacle::segIntersectRect(Seg s, Rect r) const
{
    return false;
}

bool Obstacle::rectIntersectRect(Rect r1, Rect r2) const
{
    return(r2.tl.x < r1.br.x && r2.br.y > r1.tl.y);
}

bool Obstacle::pointIntersectCircle(Point p, Circle c) const
{
    return (pow((p.x-c.c.x), 2) + pow((p.y-c.c.y), 2)) < pow(c.r, 2);
}

bool Obstacle::rectIntersectCircle(Rect r, Circle c) const
{
    Point p;

    for(int i = 0; i < 4; ++i)
    {
        switch(i)
        {
        case 0:
            p = r.tl;
            break;
        case 1:
            p = r.tr;
            break;
        case 2:
            p = r.br;
            break;
        case 3:
            p = r.bl;
            break;
        default: break;
        }
        p.x = p.x - c.c.x;
        p.x *= p.x;
        p.y = p.y - c.c.x;
        p.y *= p.y;

        if(p.x + p.y < pow(c.r, 2))
            return true;
    }
    return false;
}

bool Obstacle::circleIntersectCircle(Circle c1, Circle c2) const
{
    return false;
}


