/*!
 * \file magnet_view.h
 * \class MagnetView
 * \brief Partie vue du bonus Magnet
 * \author ShellCode
 */

#ifndef MAGNET_VIEW_H
#define MAGNET_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "effect.h"
#include "magnet_model.h"
#include "audio.h"

class MagnetView : public sf::Sprite
{
public:
    MagnetView(MagnetModel &model);
    ~MagnetView() = default;
    void update();


private:
    sf::Texture texture;
    MagnetModel &model;
    Audio sound; /*!< Son lors de la récupération de l'aimant */
    bool sound_played; /*!< true lorsque l'aimant a déjà joué le son de récupération */

};

#endif // MAGNET_VIEW_H
