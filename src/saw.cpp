#include "saw.h"

using namespace sf;
using namespace std;

Saw::Saw()
{
    assert(this->texture.loadFromFile(SAW_IMG));
    this->setTexture(texture);
    this->setOrigin(this->getLocalBounds().width / 2, this->getLocalBounds().height / 2);
}

Saw::~Saw()
{

}

void Saw::update()
{
    this->rotate(4);
}

bool Saw::checkCollision(Player &player) const
{
    PlayerModel m =  *player.getModel();

    AABB rCircle, r;
    Circle c;

    rCircle.h = this->getLocalBounds().height;
    rCircle.w = this->getLocalBounds().width;
    rCircle.x = this->Sprite::getPosition().x - rCircle.w / 2;
    rCircle.y = this->Sprite::getPosition().y - rCircle.h / 2;

    r.h = m.getHeight();
    r.w = m.getWidth();
    r.x = m.getX();
    r.y = m.getY();

    c.x = this->Sprite::getPosition().x;
    c.y = this->Sprite::getPosition().y;
    c.radius = rCircle.w / 2;

    return this->AABBintersectCircle(rCircle, r, c);
}

void Saw::action(Player &player)
{
    Utils::log("Player died");
    player.kill();
}
