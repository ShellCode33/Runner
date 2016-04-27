#include "chunk_model.h"

ChunkModel::ChunkModel(int pos_x_default) : pos_x(pos_x_default)
{

}

ChunkModel::~ChunkModel()
{
    for(Obstacle* o : this->obstacles)
        delete o;
}

std::list<Obstacle *> ChunkModel::getObstacles() const
{
    return this->obstacles;
}

void ChunkModel::addObstacle(Obstacle *obstacle)
{
    this->obstacles.push_back(obstacle);
}
