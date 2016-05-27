#ifndef MOON_VIEW_H
#define MOON_VIEW_H

#include "cassert"
#include <SFML/Graphics.hpp>
#include "moon_model.h"
#include "const.h"
#include "audio.h"

class MoonView : public sf::Sprite
{
public:
    MoonView(MoonModel &model);
    ~MoonView();

    void update();

private:
    Audio sound;
    bool sound_played;
    MoonModel & model;
    sf::Texture moon_texture;
};

#endif //MOON_VIEW_H
