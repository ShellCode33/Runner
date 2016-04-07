/*!
 * \file saw.h
 * \brief Obstacle scie circulaire
 * \author Clément
 *
 */

#ifndef SAW_VIEW_H
#define SAW_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include <algorithm>
#include <utility>
#include "saw_model.h"

class SawView : public sf::Sprite
{
public:
    SawView(SawModel &model);
    ~SawView();
    void update();

private:
    sf::Texture texture;
    SawModel& model;

};

#endif // SAW_VIEW_H
