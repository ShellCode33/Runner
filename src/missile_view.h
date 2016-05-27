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

    bool isDeadAnimFinished(); /*!< Retourne l'état de l'animation de l'explosion afin de savoir si celle-ci est terminée */
private:
    sf::Texture texture_missile;
    MissileModel &model;

    sf::Texture smoke_texture;
    Animation smoke;

    Audio audio;

    bool anim_updated; /*!< Boolean utilisé pour savoir si l'image du missile a été changée par celle de la fumée */
    bool anim_ended; /*!< Boolean utilisé pour savoir si l'animation d'explosion est terminée */

};


#endif
