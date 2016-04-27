#ifndef PIECE_MODEL_H
#define PIECE_MODEL_H

#include "obstacle.h"

class PieceModel : public Obstacle
{
public:
    PieceModel(int relat_x, int relat_y, int width, int height);
    ~PieceModel();

    void action(Player &player);
    void update();
};

#endif // PIECE_MODEL_H
