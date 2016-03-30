#ifndef WINDOW_H
/*!
 * \file window.h
 * \class WindowRunner
 * \brief Début de l'application, chargé de répartir les évênements et mettre à jour les composants graphiques.
 * \author Clément
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

class WindowRunner : sf::View
{
private:
    sf::RenderWindow *window;
    sf::VideoMode desktop;

    sf::Texture cursor_texture;
    Animation cursor;

    Menu menu;
<<<<<<< HEAD
    ScreenWait splash_screen;
    ScreenWait game_over_screen;
=======
    ScreenWait splash_screen, game_over;
>>>>>>> 3a3fd8da1b9bff9724fd3d6638d7d3c286a3ab7e
    Game game;

    State state; /*!< Enumeration des différents états du jeu*/
    AboutTab about_tab;
    OptionTab option_tab;

    void dispatchEvents(); /*!< Se charge de répartir les évênements entre les différents éléments graphiques*/


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default) const;
    State getState() const;
    void setState(const State &value);
    sf::RenderWindow & getRender() const;
};

#endif //WINDOW_H
