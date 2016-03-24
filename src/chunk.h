#ifndef CHUNK_H
#define CHUNK_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "obstacle.h"
#include <list>
#include "utils.h"
#include "const.h"

class Chunk : public sf::Drawable
{
public:
    Chunk();
    ~Chunk();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void update();
    int pos_x;
    void setPosition(int x);

    std::list<Obstacle *> getObstacles() const;

protected:
    sf::Texture texture_ground;
    sf::Sprite sprite_ground;

    sf::Texture texture_background;
    sf::Sprite sprite_background;

    std::list<Obstacle*> obstacles;

};

#endif // CHUNK_H
