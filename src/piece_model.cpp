#include "piece_model.h"

PieceModel::PieceModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height)
{

}

PieceModel::~PieceModel()
{

}

void PieceModel::action(Player &player)
{
    Utils::log("Earned 1 coin !");
}

void PieceModel::update()
{

}
