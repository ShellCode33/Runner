#ifndef MOON_H
#define MOON_H

#include "moon_model.h"
#include "moon_view.h"

class Moon
{
public:
    Moon(int relat_x, int relat_y, int width, int height);
    ~Moon();

    void update();

    MoonView * getView();
    MoonModel * getModel();


private:
    MoonModel model;
    MoonView view;

};

#endif //MOON_H
