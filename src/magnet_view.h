#ifndef MAGNET_VIEW_H
#define MAGNET_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "effect.h"
#include "magnet_model.h"

class MagnetView : public sf::Sprite
{
public:
    MagnetView(MagnetModel &model);
    ~MagnetView() = default;
    void update();


private:
    sf::Texture texture;
    MagnetModel &model;

};

#endif // MAGNET_VIEW_H
