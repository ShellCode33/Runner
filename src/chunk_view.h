#ifndef CHUNK_VIEW_H
#define CHUNK_VIEW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk_model.h"
#include "const.h"

class ChunkView : public sf::Drawable
{
public:
    ChunkView(ChunkModel &model);
    ~ChunkView();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    ChunkModel &model;
    sf::Texture texture_ground;
    sf::Sprite sprite_ground;

    sf::Texture texture_background;
    sf::Sprite sprite_background;

};

#endif // CHUNK_VIEW_H
