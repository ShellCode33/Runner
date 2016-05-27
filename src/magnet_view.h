/*!
 * \file magnet_view.h
 * \class MagnetView
 * \brief Partie vue du bonus Magnet
 * \author Clément
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
    Audio sound;
    bool sound_played;

};

#endif // MAGNET_VIEW_H
