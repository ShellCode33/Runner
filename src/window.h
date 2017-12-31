#ifndef WINDOW_H
/*!
 * \file window.h
 * \class WindowRunner
 * \brief Début de l'application, chargé de répartir les évênements et mettre à jour les composants graphiques.
 * \author ShellCode, J3ry
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
#include "config.h"

class WindowRunner : public sf::View
{
private:
    sf::RenderWindow *window;
    sf::VideoMode desktop;

    sf::Texture cursor_texture;
    Animation cursor; /*!< Remplace la souris par défaut */

    Menu menu;
    ScreenWait splash_screen;

    Game game;
    GameOver game_over;

    State state; /*!< Enumeration des différents états du jeu*/
    AboutTab about_tab; /*!< Onglet à propos */
    OptionTab option_tab; /*!< Onglet des options */

    HighScoresTab high_scores_tab; /*!< Onglet des meilleurs scores */

    void dispatchEvents(); /*!< Se charge de répartir les évênements entre les différents éléments graphiques*/


    static Config config; /*!< Config du jeu */


public:
    WindowRunner();
    ~WindowRunner();
    void create();
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states=sf::RenderStates::Default) const;
    State getState() const;
    void setState(const State &value); /*!< Défini l'état de la partie, dans le menu, en jeu, dans un onglet etc... */
    sf::RenderWindow & getRender() const;
    void launchGame(); /*! Crée une partie */
    static std::string getSetting(std::string name); /*!< Récupère une valeur dans le fichier de config */
    static void writeSetting(std::string key, std::string value); /*!< Définit une valeur dans le fichier de config */
};

#endif //WINDOW_H
