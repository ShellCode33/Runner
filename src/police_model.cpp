#include "police_model.h"

using namespace std;

PoliceModel::PoliceModel() : Movable(VIEW_WIDTH, VIEW_HEIGHT-GROUND_DEFAULT-100, 360, 108), collision(false)
{

}

PoliceModel::~PoliceModel()
{

}

void PoliceModel::update()
{
    this->setPosition(make_pair(this->getX() - POLICE_SPEED, this->getY()));
}

bool PoliceModel::checkCollision(Movable &m) const
{
    if(this->collision)
        return false;

    int reduction_collision = 50; //Afin d'avoir une hitbox plus réaliste

    AABB movable, police;

    movable.x = m.getX();
    movable.y = m.getY();
    movable.w = m.getWidth();
    movable.h = m.getHeight();

    police.w = this->getWidth() - reduction_collision;
    police.h = this->getHeight() - reduction_collision;
    police.x = this->getX() + reduction_collision / 2;
    police.y = this->getY() + reduction_collision / 2;

    return Collision::AABBintersectAABB(movable, police);
}

bool PoliceModel::getCollision() const
{
    return this->collision;
}

void PoliceModel::setCollision(bool value)
{
    this->collision = value;
}
