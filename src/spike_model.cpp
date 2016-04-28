#include "spike_model.h"
#include "game_model.h"

SpikeModel::SpikeModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height)
{

}

SpikeModel::~SpikeModel()
{

}

void SpikeModel::update()
{

}

bool SpikeModel::checkCollision(Movable &m) const
{
    AABB playerRect, spikeRect;

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    spikeRect.x = this->getX();
    spikeRect.y = this->getY();
    spikeRect.w = this->getWidth();
    spikeRect.h = this->getHeight();

    return Collision::AABBintersectAABB(playerRect, spikeRect);
}

void SpikeModel::action(GameModel &game)
{
    game.kill();
}
