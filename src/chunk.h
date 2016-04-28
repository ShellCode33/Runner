/*!
 * \file chunk.h
 * \class Chunk
 * \brief Classe permettant un découpage de l'écran afin de faciliter la génération aléatoire de Chunks prédéfinis
 * \author Clément
 */

#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk_model.h"
#include "chunk_view.h"
#include "obstacle.h"

class Chunk
{
public:
    Chunk(int pos_x_default);
    virtual ~Chunk();
    virtual void update();
    ChunkModel* getModel();
    ChunkView* getView();
    /*!
     * \brief Permet d'ajouter un obstacle au modèle
     */
    void addObstacle(Obstacle* obstacle);
    /*!
     * \brief Permet de dessiner la vue
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    ChunkModel model;
    ChunkView view;

};

#endif // CHUNK_H
