/*!
 * \file platform.h
 * \class Platform
 * \brief obstacle générique de type plateforme
 * \author J3ry
 *
 */

#ifndef PLATFORM_H
#define PLATFORM_H

#include "platform_model.h"
#include "platform_view.h"


class Platform
{
public:
    Platform(int relat_x, int relat_y, int width, int height);
    ~Platform();

    void action(GameModel &game);
    bool checkCollision(Movable &m) const;
    void update();

    PlatformModel *getModel();
    PlatformView *getView();

private:
    PlatformModel model;
    PlatformView view;

};

#endif //PLATFORM_H
