/*!
 * \file magnet.h
 * \class Magnet
 * \brief Bonus permettant d'attirer les pièces
 * \author ShellCode
 */


#ifndef MAGNET_H
#define MAGNET_H

#include "effect.h"
#include "magnet_model.h"
#include "magnet_view.h"

class Magnet : public Effect
{
public:
    Magnet(PlayerModel &player, int relat_x, int relat_y, int width, int height);
    ~Magnet() = default;
    void start(PlayerModel& player);
    void stop(PlayerModel& player);
    void update();
    MagnetModel* getModel();
    MagnetView* getView();


private:
    MagnetModel model;
    MagnetView view;

};

#endif // MAGNET_H
