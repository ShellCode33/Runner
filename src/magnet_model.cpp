#include "magnet_model.h"


MagnetModel::MagnetModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height), taken(false)
{

}

void MagnetModel::start(PlayerModel &player)
{
    player.setAttractCoins(true);
}

void MagnetModel::stop(PlayerModel &player)
{
    player.setAttractCoins(false);
}

void MagnetModel::update()
{

}

bool MagnetModel::checkCollision(Movable &m) const
{
    AABB magnetRect, playerRect;

    magnetRect.x = this->getX();
    magnetRect.y = this->getY();
    magnetRect.w = this->getWidth();
    magnetRect.h = this->getHeight();

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    return Collision::AABBintersectAABB(magnetRect, playerRect);
}

void MagnetModel::action(GameModel &game)
{
    this->taken = true;
}

bool MagnetModel::isTaken() const
{
    return this->taken;
}
