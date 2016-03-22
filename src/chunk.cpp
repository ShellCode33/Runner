#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk(int id) : pos_x(id*CHUNK_WIDTH), id(id)
{
    font.loadFromFile(ONTHEMOVE_TTF);
    text.setColor(Color::White);
    text.setFont(font);
    text.setString(to_string(id));
    text.setCharacterSize(60);

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
    target.draw(text);
}

void Chunk::update()
{
    text.setPosition(pos_x + CHUNK_WIDTH / 2, VIEW_HEIGHT / 2);
    sprite_background.setPosition(pos_x, 0);
    sprite_ground.setPosition(pos_x, VIEW_HEIGHT - GROUND);
}
