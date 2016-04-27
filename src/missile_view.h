#ifndef MISSILE_VIEW
#define MISSILE_VIEW

#include <cassert>
#include "animation.h"
#include "const.h"
#include "missile_model.h"

class MissileView : public Animation
{
public:
    MissileView(MissileModel &model);
    ~MissileView();
    void update();

private:
    sf::Texture texture_missile;
    MissileModel &model;

};


#endif
