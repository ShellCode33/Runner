#ifndef PIECE_VIEW_H
#define PIECE_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include "piece_model.h"
#include "animation.h"
#include "movable.h"
#include <algorithm>
#include <utility>

class PieceView : public Animation
{
public:
    PieceView(PieceModel &model);
    ~PieceView();
    void update();

private:
    sf::Texture piece_texture;
    PieceModel& model;
};

#endif // PIECE_VIEW_H
