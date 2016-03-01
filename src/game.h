#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "config.h"

class WindowRunner;

class Game
{
private:
    WindowRunner *window;
    Player *player;
    int speed; //Vitesse du jeu et donc du background
    Config *config;

public:
    Game(Config *config, WindowRunner *window);
    ~Game();
    void run();

};

#endif // GAME_H
