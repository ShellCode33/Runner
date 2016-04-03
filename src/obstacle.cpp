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
    PlayerModel *m =  player.getModel();

    AABB r1, r2;

    r1.w = this->getLocalBounds().width;
    r1.h = this->getLocalBounds().height;
    r1.x = this->Sprite::getPosition().x - r1.w / 2; //car origine au centre
    r1.y = this->Sprite::getPosition().y - r1.h / 2; //car origine au centre

    r2.x = m->getX();
    r2.y = m->getY();
    r2.w = m->getWidth();
    r2.h = m->getHeight();

    return this->AABBintersectAABB(r1, r2);
}

void Obstacle::action(Player &player)
{

}

bool Obstacle::pointIntersectAABB(int x, int y, AABB box) const
{
    if(x >= box.x
        && x < box.x + box.w
        && y >= box.y
        && y < box.y + box.h)
        return true;
    return false;
}

bool Obstacle::AABBintersectAABB(AABB box1, AABB box2) const
{
    if((box2.x >= box1.x + box1.w)
        || (box2.x + box2.w <= box1.x)
        || (box2.y >= box1.y + box1.h)
        || (box2.y + box2.h <= box1.y))
        return false;
    return true;
}

bool Obstacle::pointIntersectCircle(int x, int y, Circle c) const
{
    if((((x - c.x) * (x - c.x)) + ((y - c.y) * (y - c.y))) > (c.radius * c.radius))
        return false;
    return true;
}

bool Obstacle::circleIntersectCircle(Circle c1, Circle c2) const
{
    if((((c1.x - c2.x) * (c1.x - c2.x)) + ((c2.x - c2.y) * (c2.x - c2.y))) > ((c1.radius + c2.radius) * (c1.radius + c2.radius)))
        return false;

    return true;
}

bool Obstacle::AABBintersectCircle(AABB boxCircle, AABB box, Circle c) const
{
    //on test d'abord la col entre deux AABB (le second étant la box entourant le cercle) pour eviter tout calcul inutile
    if(!this->AABBintersectAABB(box, boxCircle))
        return false;


    //on test si un des sommets du rectangle est dans le cercle
    if(pointIntersectCircle(box.x, box.y, c)
            || pointIntersectCircle(box.x, box.y + box.h, c)
            || pointIntersectCircle(box.x + box.w, box.y, c)
            || pointIntersectCircle(box.x + box.w, box.y + box.h, c))
    {
        std::cout << "test 2" << std::endl;
        return true;
    }

    //on test si le centre du cercle est dans le rectangle (cas impossible pour le moment mais bon j'suis un ouf)
    if(pointIntersectAABB(c.x, c.y, box))
    {
        std::cout << "test 3" << std::endl;
        return true;
    }

    //On va maintenant tester la collision de chacun des segment du rectangle avec le centre du cercle sur les 2 axes : verticale et horizontale
    if(projectionSurSegment(c.x, c.y, box.x, box.y, box.x, box.y + box.h) || projectionSurSegment(c.x, c.y, box.x, box.y, box.x + box.w, box.y))
    {
        std::cout << "test 4" << std::endl;
        return true;
    }
    return false;
}

bool Obstacle::projectionSurSegment(int Cx, int Cy, int Ax, int Ay, int Bx, int By) const
{
    int ACx = Cx-Ax;
    int ACy = Cy-Ay;
    int ABx = Bx-Ax;
    int ABy = By-Ay;
    int BCx = Cx-Bx;
    int BCy = Cy-By;

    if (((ACx*ABx) + (ACy*ABy)) * ((BCx*ABx) + (BCy*ABy)) > 0)
        return false;
    return true;
}


