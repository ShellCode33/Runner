#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>

struct Rect
{
    int x;
    int y;
    int w;
    int h;
};

struct Circle
{
    int x;
    int y;
    int radius;
};

class Collision
{
public:
    static bool pointIntersectAABB(int x, int y, Rect box);
    static bool AABBintersectAABB(Rect box1, Rect box2);
    static bool pointIntersectCircle(int x, int y, Circle c);
    static bool circleIntersectCircle(Circle c1, Circle c2);
    static bool AABBintersectCircle(Rect boxCircle, Rect box, Circle c);
    static bool segmentProjectionPoint(int Cx,int Cy,int Ax,int Ay,int Bx,int By);
};

#endif // COLLISION_H
