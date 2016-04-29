/*!
 * \file spike.h
 * \class Spike
 * \brief Pointes au sol qui tue le joueur
 * \author Clément
 */

#ifndef SPIKE_H
#define SPIKE_H

#include "spike_model.h"
#include "spike_view.h"

class Spike
{
public:
    Spike(int relat_x, int relat_y, int width, int height);
    ~Spike();
    SpikeView* getView();
    SpikeModel* getModel();
    void update();

private:
    SpikeModel model;
    SpikeView view;

};

#endif
