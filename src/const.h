/*!
 * \file const.h
 * \brief Fichier contenant toutes les constantes utiles au jeu
 * \author Clément, Jérémie
 *
 */

#ifndef CONST_H
#define CONST_H

#include <SFML/Graphics.hpp>
#include <iostream>

//WINDOW
#define VIEW_WIDTH 1920
#define VIEW_HEIGHT 1080
#define VIEW_RATIO ((float) VIEW_WIDTH / (float) VIEW_HEIGHT)
#define FRAMERATE 60

//STRING
#define TITLE_WINDOW "Super Weed Boy"
#define SPLASH_TEXT "<< Press Space >>"
#define GAME_OVER_TEXT SPLASH_TEXT

//PATH
#define CURSOR_IMG "img/cursor.png"
#define BUTTON_MENU_IMG "img/button.png"
#define MENU_BG "img/menu_bg.png"
#define ONTHEMOVE_TTF "fonts/onthemove.ttf"
#define SPLASH_IMG "img/splash3.png"
#define PLAYER_IMG "img/player.png"
#define SNOOP_DOGG_ANIM "img/snoop.png"
#define SNOOP_DOGG_ANIM_REVERSE "img/snoop_reverse.png"
#define ILLUMINATI_IMG "img/illuminati.png"
#define GROUND_IMG "img/ground_chunk.png"
#define BACKGROUND_IMG "img/background_chunk.png"
#define FIRE_ANIM "img/fire.png"
#define SAW_IMG "img/saw.png"
#define DEAD_ANIM "img/smoke.png"
#define GAME_OVER_BG "img/gameover.png"

//GAME
#define GROUND 100
#define NB_CHUNK 4
#define CHUNK_WIDTH (VIEW_WIDTH / NB_CHUNK) //4 chunks visibles en meme temps
#define CHUNK_HEIGHT VIEW_HEIGHT
#define CHUNK_PRELOAD 10 //charge 10 chunks en mémoire
#define DEAD_LINE 100
#define FIRE_DEFAULT_POS 337


#endif // CONST_H
