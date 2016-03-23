#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "game_model.h"
#include "game_view.h"

class Game
{
public:
    Game(WindowRunner &window);
    ~Game();
    void update();
    GameView* getView();

private:
    Player player;
    GameModel game_model;
    GameView game_view;

};

#endif // GAME_H
