/*!
 * \file moon_view.h
 * \class MoonView
 * \brief Partie vue du bonus Moon
 * \author J3ry
 *
 */

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
    MoonModel & model;
    sf::Texture moon_texture;
    Audio sound; /*!< Son lors de la récupération de la lune */
    bool sound_played; /*!< true lorsque la lune a déjà joué le son de récupération */
};

#endif //MOON_VIEW_H
