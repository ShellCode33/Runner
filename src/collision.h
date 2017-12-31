/*!
 * \file collision.h
 * \class Collision
 * \brief Classe gérant toutes les collisions
 * \author J3ry
 */

#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>

/*!
 * \brief AABB(axis aligned bounding box) Rectangle dont tout les côtés sont parralèles aux deux axes (horizontaux et verticaux)
 */
struct AABB
{
    int x;
    int y;
    int w;
    int h;
};

/*!
 * \brief Circle
 */
struct Circle
{
    int x;
    int y;
    int radius;
};

class Collision
{
public:

    /*!
     * \brief pointIntersectAABB
     * \param x
     * \param y
     * \param box
     * \return vrai si collision, faux sinon
     */
    static bool pointIntersectAABB(int x, int y, AABB box);

    /*!
     * \brief AABBintersectAABB
     * \param box1
     * \param box2
     * \return vrai si collision, faux sinon
     */
    static bool AABBintersectAABB(AABB box1, AABB box2);

    /*!
     * \brief pointIntersectCircle
     * \param x
     * \param y
     * \param c
     * \return vrai si collision, faux sinon
     */
    static bool pointIntersectCircle(int x, int y, Circle c);

    /*!
     * \brief circleIntersectCircle
     * \param c1
     * \param c2
     * \return vrai si collision, faux sinon
     */
    static bool circleIntersectCircle(Circle c1, Circle c2);

    /*!
     * \brief AABBintersectCircle
     * \param boxCircle
     * \param box
     * \param c
     * \return vrai si collision, faux sinon
     */
    static bool AABBintersectCircle(AABB boxCircle, AABB box, Circle c);

    /*!
     * \brief segmentProjectionPoint
     * \param Cx
     * \param Cy
     * \param Ax
     * \param Ay
     * \param Bx
     * \param By
     * \return vrai si la projection
     */
    static bool segmentProjectionPoint(int Cx,int Cy,int Ax,int Ay,int Bx,int By);
};

#endif // COLLISION_H
