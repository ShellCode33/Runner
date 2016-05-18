#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk(int pos_x_default) : model(pos_x_default), view(model), heart_can_spawn(true), bonus_heart(nullptr)
{
    if(heart_can_spawn)
    {
        int prob = rand() % 100;

        switch(prob)
        {
            //5% prob d'apparition
            case 0:
            case 10:
            case 20:
            case 30:
            case 40:
                this->bonus_heart = new Heart(CHUNK_WIDTH / 2, CHUNK_HEIGHT - CHUNK_HEIGHT / 4, 91, 80);
                addObstacle(this->bonus_heart->getModel());
                break;
        }
    }
}

Chunk::~Chunk()
{

}

void Chunk::update()
{
    this->view.update();

    if(this->bonus_heart != nullptr)
    {
        if(this->bonus_heart->getModel()->isTaken())
        {
            removeObstacle(this->bonus_heart->getModel());
            delete this->bonus_heart;
            this->bonus_heart = nullptr;
        }

        else
        {
            this->bonus_heart->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->bonus_heart->getModel()->getRelatPosition().first, this->bonus_heart->getModel()->getRelatPosition().second));
            this->bonus_heart->update();
        }
    }
}

ChunkModel* Chunk::getModel()
{
    return &this->model;
}

ChunkView* Chunk::getView()
{
    return &this->view;
}

void Chunk::addObstacle(Obstacle *obstacle)
{
    this->model.addObstacle(obstacle);
}

void Chunk::removeObstacle(Obstacle *obstacle)
{
    this->model.removeObstacle(obstacle);
}

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->view, states);

    if(this->bonus_heart != nullptr)
        target.draw(*this->bonus_heart->getView(), states);
}
