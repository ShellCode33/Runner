#include "chunk.h"

using namespace sf;
using namespace std;

Chunk::Chunk(int pos_x_default) : model(pos_x_default), view(model)
{

}

Chunk::~Chunk()
{

}

void Chunk::update()
{
    this->view.update();
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

void Chunk::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->view, states);
}
