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

    //Afin de simplifier, on considère que le scie est un carré que l'on réduit un peu (d'où la division)
    int obst_w = this->getLocalBounds().width / 1.8;
    int obst_h = this->getLocalBounds().height / 1.8;

    //On enlève la taille car l'origine est au centre
    //On utilise Sprite:: pour récupérer la position absolue de l'image
    int obst_x = this->Sprite::getPosition().x - obst_w / 2;
    int obst_y = this->Sprite::getPosition().y - obst_h / 2;

    if((m.getX() <= obst_x + obst_w)
        && (m.getX() + m.getWidth() >= obst_x)
        && (m.getY() <= obst_y + obst_h)
        && (m.getY() + m.getHeight() >= obst_y))
        return true;

    return false;
}

void Saw::action(Player &player)
{
    Utils::log("Player died");
    player.kill();
}
