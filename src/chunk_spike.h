#ifndef CHUNK_SPIKE_H
#define CHUNK_SPIKE_H

#include "chunk.h"
#include "spike.h"

class ChunkSpike : public Chunk
{
public:
    ChunkSpike(int pos_x_default);
    ~ChunkSpike();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

private:
    Spike *spike;

};

#endif