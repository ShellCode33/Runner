#include "heart_model.h"
#include "game_model.h"

HeartModel::HeartModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height), taken(false)
{

}

HeartModel::~HeartModel()
{

}

void HeartModel::update()
{

}

bool HeartModel::checkCollision(Movable &m) const
{
    AABB movable, heart;

    heart.x = this->getX();
    heart.y = this->getY();
    heart.w = this->getWidth();
    heart.h = this->getHeight();

    movable.x = m.getX();
    movable.y = m.getY();
    movable.w = m.getWidth();
    movable.h = m.getHeight();

    return Collision::AABBintersectAABB(movable, heart);
}

void HeartModel::action(GameModel &game)
{
    game.getPlayer().getModel()->setLife(100);
    this->taken = true;
}

bool HeartModel::isTaken() const
{
    return this->taken;
}
