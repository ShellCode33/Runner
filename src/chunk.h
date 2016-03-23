#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "const.h"

class Chunk : public sf::Drawable
{
public:
    Chunk();
    ~Chunk();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    int pos_x;
    void setPosition(int x);

private:
    sf::Texture texture_ground;
    sf::Sprite sprite_ground;

    sf::Texture texture_background;
    sf::Sprite sprite_background;

};

#endif // CHUNK_H
