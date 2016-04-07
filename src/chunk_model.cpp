#include "chunk_model.h"

ChunkModel::ChunkModel() : pos_x(0)
{

}

ChunkModel::~ChunkModel()
{
    for(Obstacle* o : obstacles)
        delete o;
}

std::list<Obstacle *> ChunkModel::getObstacles() const
{
    return obstacles;
}

void ChunkModel::addObstacle(Obstacle *obstacle)
{
    this->obstacles.push_back(obstacle);
}
