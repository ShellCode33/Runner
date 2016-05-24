#include "moon_model.h"
#include "game_model.h"

using namespace std;

MoonModel::MoonModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height), taken(false)
{}

MoonModel::~MoonModel()
{

}

void MoonModel::update()
{

}

bool MoonModel::checkCollision(Movable &m) const
{
    AABB moonRect, playerRect;

    moonRect.x = this->getX();
    moonRect.y = this->getY();
    moonRect.w = this->getWidth();
    moonRect.h = this->getHeight();

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    return Collision::AABBintersectAABB(moonRect, playerRect);
}

void MoonModel::action(GameModel &game)
{
    this->taken = true;
}

bool MoonModel::isTaken() const
{
    return this->taken;
}
