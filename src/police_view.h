#ifndef POLICE_VIEW_H
#define POLICE_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "police_model.h"
#include "const.h"
#include "timer.h"

class PoliceView : public sf::Drawable
{
public:
    PoliceView(PoliceModel &model);
    ~PoliceView();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update();

private:
    PoliceModel &model;

    sf::Texture car_texture;
    sf::Sprite car;

    sf::Texture wheel_texture;
    sf::Sprite wheels[2];

    sf::CircleShape circle1, circle2;
    bool circle1_visible, circle2_visible;
    Timer timer1, timer2; //Un timer par cercle afin de créer un effet de décalage


};

#endif
