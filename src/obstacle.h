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

class Obstacle
{
public:
    Obstacle(int relat_x, int relat_y, int width, int height);
    virtual ~Obstacle();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getRelatPosition() const;
    std::pair<int, int> getSize() const;
    virtual void update() = 0;
    virtual bool checkCollision(Movable &m) = 0;

    /*!
     * \brief action que doit effectuer l'obstacle (ex : tuer le joueur)
     */
    virtual void action(Player &player) = 0;

    std::pair<int, int> getAbsolutePos() const;
    void setAbsolutePos(const std::pair<int, int> &value);

protected:
    std::pair<int, int> absolute_pos;
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */
    int width;
    int height;

};

#endif // OBSTACLE_H
