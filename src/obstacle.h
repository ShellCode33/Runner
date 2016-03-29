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

struct Point
{
    float x, y;
};

struct Seg
{
    Point a, b;
};

struct Rect
{
    Point tl, tr, bl, br;
    int w, h;
};

struct Circle
{
    Point c;
    float r;
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

    bool pointIntersectRect(Point p, Rect r) const;
    bool segIntersectRect(Seg s, Rect r) const;
    bool rectIntersectRect(Rect r1, Rect r2) const;
    bool pointIntersectCircle(Point p, Circle c) const;
    bool rectIntersectCircle(Rect r, Circle c) const;
    bool circleIntersectCircle(Circle c1, Circle c2) const;


private:
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */

};

#endif // OBSTACLE_H
