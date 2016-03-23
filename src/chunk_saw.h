#ifndef CHUNKSAW_H
#define CHUNKSAW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk.h"
#include "const.h"
#include "saw.h"

class ChunkSaw : public Chunk
{
public:
    ChunkSaw();
    ~ChunkSaw();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void update();

private:
    Saw saw;

};

#endif // CHUNKSAW_H
