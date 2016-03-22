#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "config.h"

class Game
{
private:
    Config config;
    float speed; //Vitesse du jeu et donc du background

public:
    Game();
    ~Game();

    Player player; //player model  --  SUPER SALE DE METTRE EN PUBLIC MAIS JE NE VOIS PAS COMMENT FAIRE DIFFEREMMENT POUR L'INSTANT

    void update();
};

#endif // GAME_H
