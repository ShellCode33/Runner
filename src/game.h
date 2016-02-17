#ifndef GAME_H
#define GAME_H

#include "player.h"

class WindowRunner;

class Game
{
private:
    WindowRunner *window;
    Player *player;
    int speed; //Vitesse du jeu et donc du background

public:
    Game(WindowRunner *window);
    ~Game();
    void run();

};

#endif //GAME_H
