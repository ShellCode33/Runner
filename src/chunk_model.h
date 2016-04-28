/*!
 * \file chunk_model.h
 * \class ChunkModel
 * \brief Modele de Chunk
 * \author Clément
 */

#ifndef CHUNK_MODEL_H
#define CHUNK_MODEL_H

#include <list>
#include "obstacle.h"

class ChunkModel
{
public:
    ChunkModel(int pos_x_default);
    ~ChunkModel();
    std::list<Obstacle *> getObstacles() const; /*!< Retourne la liste d'obstacles */
    void addObstacle(Obstacle* obstacle); /*!< Ajouter un obstacle au chunk */
    int pos_x; /*!< Position du chunk sur l'écran, un chunk prend toute la place selon y */

private:
    std::list<Obstacle*> obstacles; /*!< Contient les différents obstacles appartenant au chunk */
};

#endif // CHUNK_MODEL_H
