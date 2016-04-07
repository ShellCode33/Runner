#include "collision.h"

bool Collision::pointIntersectAABB(int x, int y, Rect box)
{
    return (x >= box.x
        && x < box.x + box.w
        && y >= box.y
        && y < box.y + box.h);
}

bool Collision::AABBintersectAABB(Rect box1, Rect box2)
{
    return !((box2.x >= box1.x + box1.w)
        || (box2.x + box2.w <= box1.x)
        || (box2.y >= box1.y + box1.h)
        || (box2.y + box2.h <= box1.y));
}

bool Collision::pointIntersectCircle(int x, int y, Circle c)
{
    return !((((x - c.x) * (x - c.x)) + ((y - c.y) * (y - c.y))) > (c.radius * c.radius));
}

bool Collision::circleIntersectCircle(Circle c1, Circle c2)
{
    return !((((c1.x - c2.x) * (c1.x - c2.x)) + ((c2.x - c2.y) * (c2.x - c2.y))) > ((c1.radius + c2.radius) * (c1.radius + c2.radius)));
}

bool Collision::AABBintersectCircle(Rect boxCircle, Rect box, Circle c)
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
        return true;
    }

    //on test si le centre du cercle est dans le rectangle (cas impossible pour le moment mais bon j'suis un ouf)
    if(pointIntersectAABB(c.x, c.y, box))
    {
        return true;
    }

    //On va maintenant tester la collision de chacun des segment du rectangle avec le centre du cercle sur les 2 axes : verticale et horizontale
    if(segmentProjectionPoint(c.x, c.y, box.x, box.y, box.x, box.y + box.h) || segmentProjectionPoint(c.x, c.y, box.x, box.y, box.x + box.w, box.y))
    {
        return true;
    }

    return false;
}

bool Collision::segmentProjectionPoint(int Cx, int Cy, int Ax, int Ay, int Bx, int By)
{
    int ACx = Cx-Ax;
    int ACy = Cy-Ay;
    int ABx = Bx-Ax;
    int ABy = By-Ay;
    int BCx = Cx-Bx;
    int BCy = Cy-By;

    return !(((ACx*ABx) + (ACy*ABy)) * ((BCx*ABx) + (BCy*ABy)) > 0);
}
