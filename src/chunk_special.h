/*!
 * \file chunk_special.h
 * \class ChunkSpecial
 * \brief Chunk utilisé pour les missiles
 * \author Clément
 */

#ifndef CHUNK_SPECIAL_H
#define CHUNK_SPECIAL_H

#include <utility>
#include "chunk.h"
#include "missile_seeker.h"
#include "coin.h"

class ChunkSpecial : public Chunk
{
public:
    /*!
     * \param player permet au chunk d'intéragir avec le joueur, c'est ce qui rend ce Chunk "Special"
     * \param entities est une référence vers la liste des entités de Game
     */
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
