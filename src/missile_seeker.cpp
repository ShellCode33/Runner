#include "missile_seeker.h"

using namespace sf;
using namespace std;

MissileSeeker::MissileSeeker(Player &player) : Movable(0, 0, 74, 24), player(player), missile(20.0)
{
    assert(this->texture_missile.loadFromFile(MISSILE_IMG));
    this->missile.setTexture(this->texture_missile);
}

MissileSeeker::~MissileSeeker()
{

}

void MissileSeeker::update()
{
    pair<float, float> player_pos = this->player.getModel()->getPos();
    pair<float, float> direction(player_pos.first - this->getX(), player_pos.second - this->getY());
    Utils::log("x: " + to_string(direction.first) + " - y: " + to_string(direction.second));

    int x = abs(direction.first);
    int y = abs(direction.second);

    float angle = (float)atan((float)x/y) * 180.0 / 3.141592 + 90;
    this->setPos(make_pair(this->getX() + direction.first / 100, this->getY() + direction.second / 100));

    this->missile.setRotation(this->player.getModel()->getPos().first < this->missile.getPosition().x ? angle : -angle-180);
    this->missile.setPosition(this->getX(), this->getY());
}

void MissileSeeker::action(Player &player)
{
    player.kill();
}

bool MissileSeeker::checkCollision(Movable &m)
{
    return false;
}

Animation MissileSeeker::getMissileDraw() const
{
    return this->missile;
}

Sprite MissileSeeker::getBaseDraw() const
{
    return this->base_missile;
}

void MissileSeeker::setPosition(int pos_x, int pos_y)
{
    this->base_missile.setPosition(pos_x, pos_y);
}

std::pair<int, int> MissileSeeker::getPosition() const
{
    return make_pair(this->base_missile.getPosition().x, this->base_missile.getPosition().y);
}
