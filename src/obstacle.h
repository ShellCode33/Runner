/*!
 * \file obstacle.h
 * \brief Fichier générique d'obstacle
 * \author Clément
 *
 */

#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <utility>
#include <SFML/Graphics.hpp>
#include "player.h"
#include "utils.h"

struct AABB
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

class Obstacle : public sf::Sprite
{
public:
    Obstacle(int relat_x=0, int relat_y=0);
    ~Obstacle();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getPosition() const;
    virtual void update();
    virtual bool checkCollision(Player &player) const;

    /*!
     * \brief action que doit effectuer l'obstacle (ex : tuer le joueur)
     */
    virtual void action(Player &player);

    /***GESTION DES COLLISION***/

    bool pointIntersectAABB(int x, int y, AABB box) const;
    bool AABBintersectAABB(AABB box1, AABB box2) const;
    bool pointIntersectCircle(int x, int y, Circle c) const;
    bool circleIntersectCircle(Circle c1, Circle c2) const;
    bool AABBintersectCircle(AABB boxCircle, AABB box, Circle c) const;

    bool projectionSurSegment(int Cx,int Cy,int Ax,int Ay,int Bx,int By) const;

    /***************************/

private:
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */

};

#endif // OBSTACLE_H
