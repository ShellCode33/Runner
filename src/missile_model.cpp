#include "missile_model.h"

using namespace std;

MissileModel::MissileModel(Player &player) : Movable(CHUNK_WIDTH / 2, 75, 74, 24), player(player), velocity(make_pair(0, 0)), moving(false)
{

}

MissileModel::~MissileModel()
{

}

void MissileModel::update()
{
    pair<float, float> player_pos = this->player.getModel()->getPosition();
    pair<float, float> direction(player_pos.first + this->player.getModel()->getWidth() / 2 - this->getX(), player_pos.second + this->player.getModel()->getHeight() / 2 - this->getY());
    Utils::log("x: " + to_string(direction.first) + " - y: " + to_string(direction.second));

    int x = abs(direction.first);
    int y = abs(direction.second);

    this->angle = (float)atan((float)x/y) * 180.0 / 3.141592 + 90;

    if(player_pos.first >= this->getPosition().first)
        this->angle = -angle-180;


    int x_speed = (direction.first * MISSILE_SPEED) / (x + y);
    int y_speed = (direction.second * MISSILE_SPEED) / (x + y);

    if(!moving && x < MISSILE_DETECTION)
        moving = true;

    if(moving)
        this->setPosition(make_pair(this->getX() + x_speed, this->getY() + y_speed));
}

void MissileModel::action(Player &player)
{
    player.kill();
}

bool MissileModel::checkCollision(Movable &m)
{
    AABB playerRect, missileRect;

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    missileRect.x = this->getX();
    missileRect.y = this->getY();
    missileRect.w = this->getWidth();
    missileRect.h = this->getHeight();

    return Collision::AABBintersectAABB(playerRect, missileRect);
}

float MissileModel::getAngle() const
{
    return angle;
}
