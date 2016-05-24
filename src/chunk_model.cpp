#include "chunk_model.h"

#include "moon_model.h"

ChunkModel::ChunkModel(int pos_x_default) : pos_x(pos_x_default)
{

}

ChunkModel::~ChunkModel()
{
    /*
     * //Les obstacles ne doivent pas être supprimés car ils sont contenus dans les chunks et ne sont pas alloués dynamiquement
    for(Obstacle* o : this->obstacles)
        delete o;
        */
}

std::list<Obstacle *> ChunkModel::getObstacles() const
{
    return this->obstacles;
}

void ChunkModel::addObstacle(Obstacle *obstacle)
{
    this->obstacles.push_back(obstacle);
}

void ChunkModel::removeObstacle(Obstacle *obstacle)
{
    if(dynamic_cast<MoonModel*>(obstacle) != nullptr)
        Utils::log("une moon va etre enlevée des obstacles");

    this->obstacles.remove(obstacle);
}
