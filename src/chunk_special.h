#ifndef CHUNK_SPECIAL_H
#define CHUNK_SPECIAL_H

#include <utility>
#include "chunk.h"
#include "missile_seeker.h"

class ChunkSpecial : public Chunk
{
public:
    ChunkSpecial(int pos_x_default, Player &player, std::list<Entity *> &entities);
    ~ChunkSpecial();
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    Player &player;
    sf::Texture texture_base;
    sf::Sprite base_missile;
    MissileSeeker *missile;
    std::list<Entity *> &entities;

};

#endif // CHUNK_SPECIAL_H
