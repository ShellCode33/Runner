#include "saw.h"

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
