#include "coin_model.h"
#include "game_model.h"

CoinModel::CoinModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height), taken(false)
{

}

CoinModel::~CoinModel()
{

}

void CoinModel::action(GameModel &game)
{
    Utils::log("Earned 1 coin !");
    this->taken = true;
    game.addBonusScore(100);
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

    coinRect.w = this->getWidth();
    coinRect.h = this->getHeight();
    coinRect.x = this->getX() - coinRect.w / 2;
    coinRect.y = this->getY() - coinRect.h / 2;

    return Collision::AABBintersectAABB(playerRect, coinRect);
}

bool CoinModel::isTaken() const
{
    return this->taken;
}
