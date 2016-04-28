#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "utils.h"
#include "timer.h"
#include "chunk.h"
#include "entity.h"
#include "chunk_saw.h"
#include "chunk_special.h"
#include "chunk_spike.h"

class GameModel
{
private:
    unsigned long score;
    int fire_offset; /*!< correspond à l'avancement du feu dans la partie */
    int fire_speed; /*!< Nombre de pixel d'avancement du feu */
    int time_per_move; /*!< Vitesse d'approche du feu, évolue avec le temps */
    Timer game_begin;
    Timer timer;
    Timer difficulty_timer;
    Player &player;
    std::list<Chunk *> &chunks;
    std::list<Entity *> &entities;
    Chunk *randomChunk(int pos_x_default) const;

public:
    GameModel(Player &player, std::list<Chunk *> &chunks, std::list<Entity *> &entities);
    ~GameModel();

    void update();
    unsigned long getScore() const;
    int getFireOffset() const;
    void setFireOffset(int value);
    std::list<Chunk *> getVisibleChunks() const;
    void setScore(unsigned long value);
    void kill();
};

#endif // GAMEMODEL_H
