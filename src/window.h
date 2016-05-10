#ifndef WINDOW_H
/*!
 * \file window.h
 * \class WindowRunner
 * \brief Début de l'application, chargé de répartir les évênements et mettre à jour les composants graphiques.
 * \author Clément, Jérémie
 */

#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <cassert>
#include "const.h"
#include "menu.h"
#include "screenwait.h"
#include "utils.h"
#include "gamestate.h"
#include "about_tab.h"
#include "option_tab.h"
#include "game.h"
#include "gameover.h"
#include "high_scores_tab.h"

class WindowRunner : sf::View
{
private:
    sf::RenderWindow *window;
    sf::VideoMode desktop;

    sf::Texture cursor_texture;
    Animation cursor;

    Menu menu;
    ScreenWait splash_screen;

    Game game;
    GameOver game_over;

    State state; /*!< Enumeration des différents états du jeu*/
    AboutTab about_tab;
    OptionTab option_tab;

    HighScoresTab high_scores_tab;

    void dispatchEvents(); /*!< Se charge de répartir les évênements entre les différents éléments graphiques*/


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default) const;
    State getState() const;
    void setState(const State &value);
    sf::RenderWindow & getRender() const;
    void launchGame();
};

#endif //WINDOW_H
