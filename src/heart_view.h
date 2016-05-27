/*!
 * \file heart_view.h
 * \class HeartView
 * \brief Partie vue du bonus Heart
 * \author Clément
 */

#ifndef HEART_VIEW_H
#define HEART_VIEW_H

#include <SFML/Graphics.hpp>
#include "animation.h"
#include "heart_model.h"
#include <cassert>
#include "audio.h"

class HeartView : public Animation
{
public:
    HeartView(HeartModel & model);
    ~HeartView();
    void update();

private:
    HeartModel & model;
    sf::Texture heart_texture;
    Audio sound;
    bool sound_played;

};


#endif
