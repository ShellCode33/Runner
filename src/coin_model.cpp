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
    player.getModel()->setScore(player.getModel()->getScore() + 100);
}

void CoinModel::update()
{

}

bool CoinModel::checkCollision(Movable &m) const
{
    AABB playerRect, coinRect;

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    coinRect.x = this->getX();
    coinRect.y = this->getY();
    coinRect.w = this->getWidth();
    coinRect.h = this->getHeight();

    return Collision::AABBintersectAABB(playerRect, coinRect);
}
