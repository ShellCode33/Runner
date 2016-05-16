#ifndef PLATFORM_H
#define PLATFORM_H

#include "entity.h"
#include "platform_model.h"
#include "platform_view.h"


class Platform : public Entity
{
public:
    Platform();
    ~Platform();

    void draw(sf::RenderTarget& target, sf::RenderStates states);
    void action(Player &player);
    bool checkCollision(Movable &m);

private:

    //Player & player;
    PlatformModel model;
    PlatformView view;

};

#endif //PLATFORM_H
