#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "game_model.h"
#include "game_view.h"
#include "gamestate.h"

class WindowRunner;

class Game
{
public:
    Game(WindowRunner &window);
    ~Game();
    void update();
    GameView* getView();

    void create();
private:
    WindowRunner &window;

    /*!
     * \brief Un pointeur est utilisé de manière à réinitialiser une partie plus facilement à l'aide d'un new/delete
     */
    Player *player;

    /*!
     * \brief Un pointeur est utilisé de manière à réinitialiser une partie plus facilement à l'aide d'un new/delete
     */
    GameModel *game_model;

    /*!
     * \brief Un pointeur est utilisé de manière à réinitialiser une partie plus facilement à l'aide d'un new/delete
     */
    GameView *game_view;

    bool game_over;

};

#endif // GAME_H
