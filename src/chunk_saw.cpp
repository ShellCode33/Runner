#include "chunk_saw.h"

ChunkSaw::ChunkSaw()
{
    this->saw = new Saw();
    this->obstacles.push_back(this->saw);
    this->saw->setPositionRelat(CHUNK_WIDTH / 2, CHUNK_HEIGHT - this->saw->getLocalBounds().height);
}

ChunkSaw::~ChunkSaw()
{

}

void ChunkSaw::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*this->saw, states);
}

void ChunkSaw::update()
{
    Chunk::update();
    this->saw->update();
    this->saw->setPosition(this->pos_x + this->saw->getPosition().first, this->saw->getPosition().second);
}
