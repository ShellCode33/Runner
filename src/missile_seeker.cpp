#include "missile_seeker.h"

using namespace sf;
using namespace std;

MissileSeeker::MissileSeeker(Player &player) : player(player)
{
    assert(this->texture.loadFromFile(MISSILE_IMG));
    this->setTexture(this->texture);
}

MissileSeeker::~MissileSeeker()
{

}

void MissileSeeker::update()
{
    int x = abs(player.getModel()->getPos().first - this->Sprite::getPosition().x);
    int y = abs(player.getModel()->getPos().second - this->Sprite::getPosition().y);
    float angle = (float)atan((float)x/y) * 180.0 / 3.141592 + 90;

    this->setRotation(player.getModel()->getPos().first < this->Sprite::getPosition().x ? angle : -angle-180);
}

void MissileSeeker::action(Player &player)
{
    player.kill();
}

bool MissileSeeker::checkCollision(Movable &m)
{
    return false;
}
