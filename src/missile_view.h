/*!
 * \file missile_view.h
 * \class MissileView
 * \brief Vue du missile suiveur
 * \author Clément
 *
 */

#ifndef MISSILE_VIEW
#define MISSILE_VIEW

#include <cassert>
#include "animation.h"
#include "const.h"
#include "missile_model.h"
#include "audio.h"

class MissileView : public Animation
{
public:
    MissileView(MissileModel &model);
    ~MissileView();
    void update();

    bool isDeadAnimFinished();
private:
    sf::Texture texture_missile;
    MissileModel &model;

    sf::Texture smoke_texture;
    Animation smoke;

    Audio audio;

    bool anim_updated;
    bool anim_ended;

};


#endif
