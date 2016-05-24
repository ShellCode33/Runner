#include "chunk_spike.h"

using namespace std;

ChunkSpike::ChunkSpike(int pos_x_default, Player &player) : Chunk(pos_x_default, player)
{
    spawnBonusRandom();
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

    Platform *platform = new Platform(0, CHUNK_HEIGHT - GROUND_DEFAULT - this->spike->getView()->getLocalBounds().height * 2, 192, 20);
    this->platforms.push_back(platform);
    this->addObstacle(platform->getModel());
}

ChunkSpike::~ChunkSpike()
{
    delete this->spike;
}

void ChunkSpike::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Chunk::draw(target, states);
    target.draw(*this->spike->getView(), states);

    for(Platform *p : this->platforms)
        target.draw(*p->getView(), states);
}

void ChunkSpike::update()
{
    Chunk::update();
    this->spike->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->spike->getModel()->getRelatPosition().first, this->spike->getModel()->getRelatPosition().second));
    this->spike->update();

    for(Platform *p : this->platforms)
    {
        p->getModel()->setPosition((make_pair(this->getModel()->pos_x + p->getModel()->getRelatPosition().first, p->getModel()->getRelatPosition().second)));
        p->update();
    }
}
