#ifndef MOON_VIEW_H
#define MOON_VIEW_H

#include "animation.h"
#include "cassert"
#include "SFML/Graphics.hpp"
#include "moon_model.h"
#include "const.h"

class MoonView : public Animation
{
public:
    MoonView(MoonModel &model);
    ~MoonView();

    void update();

private:
    MoonModel & model;
    sf::Texture moon_texture;
};

#endif //MOON_VIEW_H
