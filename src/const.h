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
#define SPLASH_TEXT " "

//PATH
#define CURSOR_IMG "img/cursor.png"
#define BUTTON_MENU_IMG "img/button4.png"
#define MENU_BG "img/menu_bg.png"
#define ONTHEMOVE_TTF "fonts/onthemove.ttf"
#define SPLASH_IMG "img/splash4.png"
#define PLAYER_IMG "img/player4.png"
#define PLAYER_RUNNING_IMG "img/player_running.png"
#define SNOOP_DOGG_ANIM "img/snoop.png"
#define SNOOP_DOGG_ANIM_REVERSE "img/snoop_reverse.png"
#define ILLUMINATI_IMG "img/illuminati.png"
#define GROUND_IMG "img/ground_chunk2.png"
#define BACKGROUND_IMG "img/background_chunk.png"
#define FIRE_ANIM "img/fire.png"
#define SAW_IMG "img/saw.png"
#define DEAD_ANIM "img/smoke.png"
#define GAME_OVER_BG "img/gameover.png"
#define GAME_OVER_BOARD "img/gameover_board.png"
#define LAVA_IMG "img/lava.png"

//GAME
#define GROUND_DEFAULT 100
#define NB_CHUNK 4
#define CHUNK_WIDTH (VIEW_WIDTH / NB_CHUNK) //4 chunks visibles en meme temps
#define CHUNK_HEIGHT VIEW_HEIGHT
#define CHUNK_PRELOAD 6 //charge X chunks en mémoire
#define DEAD_LINE_DEFAULT 100
#define FIRE_DEFAULT_POS 337
#define MIN_FIRE_POS -150 //Lorsque le joueur avance, le feu recule mais ne va jamais plus loin que cette valeur
#define SAW_WIDTH 130
#define SAW_RADIUS SAW_WIDTH / 2


#endif // CONST_H
