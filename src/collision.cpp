#include "collision.h"

bool Collision::pointIntersectAABB(int x, int y, AABB box)
{
    if(x >= box.x
        && x < box.x + box.w
        && y >= box.y
        && y < box.y + box.h)
        return true;
    return false;
}

bool Collision::AABBintersectAABB(AABB box1, AABB box2)
{
    if((box2.x >= box1.x + box1.w)
        || (box2.x + box2.w <= box1.x)
        || (box2.y >= box1.y + box1.h)
        || (box2.y + box2.h <= box1.y))
        return false;
    return true;
}

bool Collision::pointIntersectCircle(int x, int y, Circle c)
{
    if((((x - c.x) * (x - c.x)) + ((y - c.y) * (y - c.y))) > (c.radius * c.radius))
        return false;
    return true;
}

bool Collision::circleIntersectCircle(Circle c1, Circle c2)
{
    if((((c1.x - c2.x) * (c1.x - c2.x)) + ((c2.x - c2.y) * (c2.x - c2.y))) > ((c1.radius + c2.radius) * (c1.radius + c2.radius)))
        return false;

    return true;
}

bool Collision::AABBintersectCircle(AABB boxCircle, AABB box, Circle c)
{
    //on test d'abord la col entre deux AABB (le second étant la box entourant le cercle) pour eviter tout calcul inutile
    if(!AABBintersectAABB(box, boxCircle))
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

bool Collision::projectionSurSegment(int Cx, int Cy, int Ax, int Ay, int Bx, int By)
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
