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
    Chunk();
    virtual ~Chunk();
    virtual void update();
    ChunkModel* getModel();
    ChunkView* getView();
    void addObstacle(Obstacle* obstacle);

    /*! Cett methode ne dessine pas directement les éléments graphiques mais ordonne à la vue de le faire */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    ChunkModel model;
    ChunkView view;

};

#endif // CHUNK_H
