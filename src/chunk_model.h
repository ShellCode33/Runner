#ifndef CHUNK_MODEL_H
#define CHUNK_MODEL_H

#include <list>
#include "obstacle.h"

class ChunkModel
{
public:
    ChunkModel(int pos_x_default);
    ~ChunkModel();
    std::list<Obstacle *> getObstacles() const;
    void addObstacle(Obstacle* obstacle);
    int pos_x;

private:
    std::list<Obstacle*> obstacles;
};

#endif // CHUNK_MODEL_H
