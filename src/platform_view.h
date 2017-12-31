/*!
 * \file platform_view.h
 * \class PlatformView
 * \brief Partie vue de l'obstacle
 * \author J3ry
 *
 */

#ifndef PLATFORM_VIEW_H
#define PLATFORM_VIEW_H

#include "SFML/Graphics.hpp"
#include "platform_model.h"
#include "cassert"
#include "const.h"

class PlatformView : public sf::Sprite
{
public:
    PlatformView(PlatformModel &model);
    ~PlatformView();

    void update();

private:
    PlatformModel &model;
    sf::Texture texture_platform;
};

#endif //PLATFORM_VIEW_H
