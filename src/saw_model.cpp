#include "saw_model.h"

SawModel::SawModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height)
{

}

SawModel::~SawModel()
{

}

bool SawModel::checkCollision(Movable &m) const
{
    Rect rCircle, r;
    Circle c;

    rCircle.w = this->width;
    rCircle.h = this->height;
    rCircle.x = this->getPosition().first - rCircle.w / 2;
    rCircle.y = this->getPosition().second - rCircle.h / 2;

    c.x = this->getPosition().first;
    c.y = this->getPosition().second;
    c.radius = rCircle.w / 2;

    r.w = m.getWidth();
    r.h = m.getHeight();
    r.x = m.getX();
    r.y = m.getY();

    return Collision::AABBintersectCircle(rCircle, r, c);
}

void SawModel::update()
{

}

void SawModel::action(Player &player)
{
    Utils::log("Player died");
    player.kill();
}
