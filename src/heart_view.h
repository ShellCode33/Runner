#ifndef HEART_VIEW_H
#define HEART_VIEW_H

#include <SFML/Graphics.hpp>
#include "animation.h"
#include "heart_model.h"
#include <cassert>

class HeartView : public Animation
{
public:
    HeartView(HeartModel & model);
    ~HeartView();
    void update();

private:
    HeartModel & model;
    sf::Texture heart_texture;

};


#endif
