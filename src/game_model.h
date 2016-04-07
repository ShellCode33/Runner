#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "utils.h"
#include "timer.h"
#include "chunk.h"

class GameModel
{
private:
    unsigned long score;
    int fire_offset; /*!< correspond à l'avancement du feu dans la partie */
    int fire_speed; /*!< Nombre de pixel d'avancement du feu */
    int time_per_move; /*!< Vitesse d'approche du feu, évolue avec le temps */
    Timer game_begin;
    Timer timer;
    Player &player;
    std::list<Chunk *> &chunks;
    Chunk *randomChunk() const;

public:
    GameModel(Player &player, std::list<Chunk *> &chunks);
    ~GameModel();

    void update();
    unsigned long getScore() const;
    int getFireOffset() const;
    void setFireOffset(int value);
    std::list<Chunk *> getVisibleChunks() const;
};

#endif // GAMEMODEL_H
