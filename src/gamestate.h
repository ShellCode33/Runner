/*!
 * \file gamestate.h
 * \brief Enumeration des différents états du jeu
 * \author Clément
 *
 */

#ifndef GAMESTATE_H
#define GAMESTATE_H

enum State
{
    SPLASH,     /*!< Splash Screen au lancement du jeu */
    MENU,       /*!< Menu après le splash screen */
    CAMPAIGN,   /*!< Mode Campagne avec des niveaux */
    SURVIVAL,   /*!< Mode Survival infini */
    OPTIONS,    /*!< Options du jeu */
    ABOUT,      /*!< A propos */
    GAME_OVER,  /*!< Le joueur a perdu, écran de défaite */
    EXIT        /*!< Quitte le jeu */
};

#endif
