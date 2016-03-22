#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk() : pos_x(0)
{
    texture_ground.loadFromFile(GROUND_IMG);
    sprite_ground.setTexture(texture_ground);

    texture_background.loadFromFile(BACKGROUND_IMG);
    sprite_background.setTexture(texture_background);
}

Chunk::~Chunk()
{

}

void Chunk::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(sprite_ground);
    target.draw(sprite_background);
}

void Chunk::setPosition(int x)
{
    pos_x = x;
}

void Chunk::update()
{
    sprite_background.setPosition(pos_x, 0);
    sprite_ground.setPosition(pos_x, VIEW_HEIGHT - GROUND);
}
