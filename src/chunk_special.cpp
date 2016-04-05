#include "chunk_special.h"

ChunkSpecial::ChunkSpecial(Player &player)
{
    this->missile = new MissileSeeker(player);
    this->missile->setPositionRelat(CHUNK_WIDTH / 2, 100);
    this->obstacles.push_back(this->missile);
}

ChunkSpecial::~ChunkSpecial()
{

}

void ChunkSpecial::update()
{
    Chunk::update();
    this->missile->update();
    this->missile->setPosition(this->pos_x + this->missile->getPosition().first, this->missile->getPosition().second);
}

void ChunkSpecial::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*missile, states);
}
