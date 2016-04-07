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
#include "collision.h"
#include "movable.h"

class Obstacle : public Movable
{
public:
    Obstacle(int relat_x, int relat_y, int width, int height);
    virtual ~Obstacle();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getRelatPosition() const;
    virtual void update() = 0;
    virtual bool checkCollision(Movable &m) const = 0;

    /*!
     * \brief action que doit effectuer l'obstacle (ex : tuer le joueur)
     */
    virtual void action(Player &player) = 0;

protected:
    //Les coordonnées absolues sont dans Movable
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */

};

#endif // OBSTACLE_H
