#include "chunk_spike.h"

using namespace std;

ChunkSpike::ChunkSpike(int pos_x_default) : Chunk(pos_x_default)
{
    this->spike = new Spike(0, 0, 240, 50);
    this->spike->getModel()->setPositionRelat((CHUNK_WIDTH - this->spike->getView()->getLocalBounds().width) / 2, CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height);
    this->addObstacle(this->spike->getModel());
}

ChunkSpike::~ChunkSpike()
{

}

void ChunkSpike::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*this->spike->getView(), states);
}

void ChunkSpike::update()
{
    Chunk::update();
    this->spike->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->spike->getModel()->getRelatPosition().first, this->spike->getModel()->getRelatPosition().second));
    this->spike->update();
}
