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
}

Chunk::~Chunk()
{

}

void Chunk::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(text);
}

void Chunk::update()
{
    text.setPosition(pos_x + CHUNK_WIDTH / 2, VIEW_HEIGHT / 2);
}
