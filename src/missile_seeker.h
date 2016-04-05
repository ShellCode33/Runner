#ifndef MISSILE_SEEKER_H
#define MISSILE_SEEKER_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"

class MissileSeeker : public Obstacle
{
public:
    /*!
     * \brief MissileSeeker
     * \param player : necessaire pour "suivre" le joueur
     */
    MissileSeeker(Player &player);
    ~MissileSeeker();
    void update();
    void action(Player &player);
    bool checkCollision(Movable &m);

private:
    Player &player;
    sf::Texture texture;

};

#endif // MISSILE_SEEKER_H
