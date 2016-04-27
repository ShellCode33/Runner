#ifndef MISSILE_SEEKER_H
#define MISSILE_SEEKER_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "missile_model.h"
#include "missile_view.h"
#include "entity.h"

class MissileSeeker : public Entity
{
public:
    /*!
     * \brief MissileSeeker
     * \param player : necessaire pour "suivre" le joueur
     */
    MissileSeeker(Player &player);
    ~MissileSeeker();

    void update();
    MissileModel* getModel();
    MissileView* getView();
    void draw(sf::RenderTarget &target, sf::RenderStates states);
    void action(Player &player);
    bool checkCollision(Movable &m);

private:
    Player &player;
    MissileModel model;
    MissileView view;


};

#endif // MISSILE_SEEKER_H
