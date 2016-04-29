/*!
 * \file saw.h
 * \class Saw
 * \brief Scie circulaire au sol qui tue le joueur
 * \author Clément
 */

#ifndef SAW_H
#define SAW_H

#include "saw_model.h"
#include "saw_view.h"

class Saw
{
public:
    Saw(int relat_x, int relat_y, int width, int height);
    ~Saw();
    SawModel* getModel();
    SawView* getView();
    void update();

private:
    SawModel model;
    SawView view;
};

#endif // SAW_H
