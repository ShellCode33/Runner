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
    void removeObstacle(Obstacle* obstacle);
    int pos_x; /*!< Position du chunk sur l'écran, un chunk prend toute la place selon y */
    bool isInChunk(Movable &m) const;

    unsigned int getTheme() const;
    void update();

private:
    std::list<Obstacle*> obstacles; /*!< Contient les différents obstacles appartenant au chunk */

    static unsigned short num_theme; /*!< Contient le numéro du thème, est incrémenté toutes les 30 secondes */
    static Timer change_background_timer; /*!< Toutes les 30 secondes on change de thème */
};

#endif // CHUNK_MODEL_H
