/*!
 * \file chunk_spike.h
 * \class ChunkSpike
 * \brief Chunk utilisé pour les pointes
 * \author ShellCode
 */

#ifndef CHUNK_SPIKE_H
#define CHUNK_SPIKE_H

#include "chunk.h"
#include "spike.h"
#include "coin.h"

class ChunkSpike : public Chunk
{
public:
    ChunkSpike(int pos_x_default, Player &player);
    ~ChunkSpike();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();

private:
    Spike *spike;

};

#endif
