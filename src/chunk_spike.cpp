#include "chunk_spike.h"

using namespace std;

ChunkSpike::ChunkSpike(int pos_x_default) : Chunk(pos_x_default)
{
    this->spike = new Spike(0, 0, 240, 50);
    this->spike->getModel()->setPositionRelat((CHUNK_WIDTH - this->spike->getView()->getLocalBounds().width) / 2, CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height);
    this->addObstacle(this->spike->getModel());


    for(unsigned int i = 0; i < COIN_COUNT; i++)
    {
        this->coins[i] = new Coin(0, 0, 32, 32);
        this->addObstacle(this->coins[i]->getModel());
        this->coins[i]->getModel()->setPositionRelat(((CHUNK_WIDTH - this->spike->getView()->getLocalBounds().width) / 2) + 32 * i, CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height * 2);
    }
}

ChunkSpike::~ChunkSpike()
{

}

void ChunkSpike::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*this->spike->getView(), states);

    for(unsigned int i = 0; i < COIN_COUNT; i++)
    {
        target.draw(*this->coins[i]->getView(), states);
    }
}

void ChunkSpike::update()
{
    Chunk::update();
    this->spike->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->spike->getModel()->getRelatPosition().first, this->spike->getModel()->getRelatPosition().second));
    this->spike->update();

    for(unsigned int i = 0; i < COIN_COUNT; i++)
    {
        if(!this->coins[i]->getModel()->getTaken())
        {
            this->coins[i]->getModel()->setPosition((make_pair(this->getModel()->pos_x + this->coins[i]->getModel()->getRelatPosition().first, this->coins[i]->getModel()->getRelatPosition().second)));
            this->coins[i]->update();
        }
        else
            this->removeObstacle(this->coins[i]->getModel());
    }
}
