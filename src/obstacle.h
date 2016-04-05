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

class Obstacle : public sf::Sprite
{
public:
    Obstacle(int relat_x=0, int relat_y=0);
    virtual ~Obstacle();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getPosition() const;
    virtual void update() = 0;
    virtual bool checkCollision(Movable &m) = 0;

    /*!
     * \brief action que doit effectuer l'obstacle (ex : tuer le joueur)
     */
    virtual void action(Player &player) = 0;

private:
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */

};

#endif // OBSTACLE_H
