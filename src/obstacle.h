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
#include "movable.h"

class Obstacle : public sf::Sprite
{
public:
    Obstacle(int relat_x=0, int relat_y=0);
    ~Obstacle();
    void setPositionRelat(const int x, const int y);
    std::pair<int, int> getPosition() const;
    void update();
    bool checkCollision(Movable &player);

private:
    int relat_x; /*!< Position relative au chunk de l'axe X */
    int relat_y; /*!< Position relative au chunk de l'axe Y */

};

#endif // OBSTACLE_H
