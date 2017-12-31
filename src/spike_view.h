/*!
 * \file spike_view.h
 * \class SpikeView
 * \brief Vue des pics
 * \author ShellCode
 */

#ifndef SPIKE_VIEW_H
#define SPIKE_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "spike_model.h"
#include "const.h"

class SpikeView : public sf::Sprite
{
public:
    SpikeView(SpikeModel &model);
    ~SpikeView();
    void update();

private:
    SpikeModel &model;
    sf::Texture texture;

};

#endif
