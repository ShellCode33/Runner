#ifndef CHUNKSAW_H
#define CHUNKSAW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "chunk.h"
#include "const.h"
#include "utils.h"
#include "saw.h"


#define MAX_SAW_COUNT 4

class ChunkSaw : public Chunk
{
public:
    ChunkSaw(int pos_x_default);
    ~ChunkSaw();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

private:
    Saw *saw[MAX_SAW_COUNT];
    unsigned short nb_saw;

};

#endif // CHUNKSAW_H
