#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk(int pos_x_default) : model(pos_x_default), view(model), bonus_heart(nullptr), bonus_moon(nullptr), heart_can_spawn(true)
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
                this->addObstacle(this->bonus_heart->getModel());
                break;

            case 1:
            case 11:
            case 21:
            case 31:
            case 41:
                this->bonus_moon = new Moon(CHUNK_WIDTH / 2, CHUNK_HEIGHT - CHUNK_HEIGHT / 4, 60, 60);
                this->addObstacle(this->bonus_moon->getModel());
                break;

        default:break;
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

    if(this->bonus_moon != nullptr)
    {
        if(this->bonus_moon->getModel()->isTaken())
        {
            removeObstacle(this->bonus_moon->getModel());
            delete this->bonus_moon;
            this->bonus_moon = nullptr;
        }
        else
        {
            this->bonus_moon->getModel()->setPosition(make_pair(this->getModel()->pos_x + this->bonus_moon->getModel()->getRelatPosition().first, this->bonus_moon->getModel()->getRelatPosition().second));
            this->bonus_moon->update();
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

    if(this->bonus_moon != nullptr)
        target.draw(*this->bonus_moon->getView(), states);
}
