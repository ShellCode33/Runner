#include "chunk_spike.h"

using namespace std;

ChunkSpike::ChunkSpike(int pos_x_default) : Chunk(pos_x_default)
{
    this->spike = new Spike(0, 0, 240, 50);
    this->spike->getModel()->setPositionRelat((CHUNK_WIDTH - this->spike->getView()->getLocalBounds().width) / 2, CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height);
    this->addObstacle(this->spike->getModel());


    for(int i = -2; i <= 2; i++) //5pièces en tout
    {
        int pos_y;

        if(i == -2 || i == 2) //Décalage des pièces aux extremitées
            pos_y = CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height * 2;

        else
            pos_y = CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height * 3;

        Coin *coin = new Coin(CHUNK_WIDTH / 2 + 32 * i, pos_y, 32, 32);
        coin->getView()->setOrigin(coin->getModel()->getWidth() / 2, coin->getModel()->getHeight() / 2);
        this->coins.push_back(coin);
        this->addObstacle(coin->getModel());
    }
}

ChunkSpike::~ChunkSpike()
{

}

void ChunkSpike::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*this->spike->getView(), states);

    for(Coin *c : this->coins)
        target.draw(*c->getView(), states);
}

void ChunkSpike::update()
{
    Chunk::update();
    this->spike->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->spike->getModel()->getRelatPosition().first, this->spike->getModel()->getRelatPosition().second));
    this->spike->update();

    list<Coin*> to_remove;

    for(Coin *c : this->coins)
    {
        if(!c->getModel()->isTaken())
        {
            c->getModel()->setPosition((make_pair(this->getModel()->pos_x + c->getModel()->getRelatPosition().first, c->getModel()->getRelatPosition().second)));
            c->update();
        }

        else
            to_remove.push_back(c);
    }

    for(Coin *c : to_remove)
    {
        this->removeObstacle(c->getModel());
        this->coins.remove(c);
        delete c;
    }
}
