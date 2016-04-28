#include "coin_model.h"

CoinModel::CoinModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height)
{

}

CoinModel::~CoinModel()
{

}

void CoinModel::action(Player &player)
{
    Utils::log("Earned 1 coin !");

}

void CoinModel::update()
{

}

bool CoinModel::checkCollision(Movable &m) const
{
    return true;
}
