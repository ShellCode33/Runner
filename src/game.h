#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "config.h"

class Game
{
private:
    Player player;
    int speed; //Vitesse du jeu et donc du background
    Config config;

public:
    Game();
    ~Game();

};

#endif // GAME_H
