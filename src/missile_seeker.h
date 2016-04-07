#ifndef MISSILE_SEEKER_H
#define MISSILE_SEEKER_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"

//L'heritage movable est pour le missile lui meme, pas la base
class MissileSeeker : public Movable
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
    Animation getMissileDraw() const;
    sf::Sprite getBaseDraw() const;

    //Get et set position pour la base
    void setPosition(int pos_x, int pos_y);
    std::pair<int, int> getPosition() const;

private:
    Player &player;
    sf::Texture texture_missile, texture_base;
    sf::Sprite base_missile;
    Animation missile;


};

#endif // MISSILE_SEEKER_H
