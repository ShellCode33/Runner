/*!
 * \file moon.h
 * \class Moon
 * \brief Bonus appliquant une gravité différent au player
 * \author J3ry
 *
 */

#ifndef MOON_H
#define MOON_H

#include "moon_model.h"
#include "moon_view.h"
#include "effect.h"

class Moon : public Effect
{
public:
    Moon(PlayerModel &player, int relat_x, int relat_y, int width, int height);
    ~Moon();

    void update();

    MoonView * getView();
    MoonModel * getModel();

    void start(PlayerModel &player);
    void stop(PlayerModel &player);


private:
    MoonModel model;
    MoonView view;

};

#endif //MOON_H
