#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "config.h"

class Game
{
private:
    Config config;
    Player player;
    float speed; //Vitesse du jeu et donc du background

public:
    Game();
    ~Game();

};

#endif // GAME_H
