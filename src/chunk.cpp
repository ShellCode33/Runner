#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk() : pos_x(0)
{
    this->texture_ground.loadFromFile(GROUND_IMG);
    this->sprite_ground.setTexture(this->texture_ground);

    this->texture_background.loadFromFile(BACKGROUND_IMG);
    this->sprite_background.setTexture(this->texture_background);
}

Chunk::~Chunk()
{

}

void Chunk::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(this->sprite_ground, states);
    target.draw(this->sprite_background, states);
}

void Chunk::setPosition(int x)
{
    this->pos_x = x;
}

void Chunk::update()
{
    this->sprite_background.setPosition(this->pos_x, 0);
    this->sprite_ground.setPosition(this->pos_x, VIEW_HEIGHT - GROUND);
}
