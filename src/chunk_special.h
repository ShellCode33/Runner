#ifndef CHUNK_SPECIAL_H
#define CHUNK_SPECIAL_H

#include "chunk.h"
#include "missile_seeker.h"

class ChunkSpecial : public Chunk
{
public:
    ChunkSpecial(Player &player);
    ~ChunkSpecial();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    MissileSeeker *missile;

};

#endif // CHUNK_SPECIAL_H
