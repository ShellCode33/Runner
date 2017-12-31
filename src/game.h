/*!
 * \file game.h
 * \class Game
 * \author ShellCode
 */

#ifndef GAME_H
#define GAME_H

#include <map>
#include "player.h"
#include "game_model.h"
#include "game_view.h"
#include "gamestate.h"
#include "audio.h"

class WindowRunner;

class Game
{
public:
    Game(WindowRunner &window);
    ~Game();
    void update();
    GameView* getView();
    GameModel* getModel();

    void create();
private:
    Audio audio, gameover;

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

    bool game_over; /*!< Le joueur a perdu si le boolean est à true */

    std::list<Chunk*> chunks; /*!< Liste qui stoque les chunks de la partie */
    std::list<Entity *> entities; /*!< Liste qui stoque des objets qui doivent être dessinés en dernier!! (ex: missile) Afin d'apparaitre quelle que soit sa position sur l'écran */

};

#endif // GAME_H
