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
#define GAME_OVER_TEXT " "

//PATH
#define CURSOR_IMG "img/cursor.png"
#define BUTTON_MENU_IMG "img/button5.png"
#define MENU_BG "img/menu_bg.png"
#define HIGHSCORES_BG "img/highscores_bg.jpeg"
#define ONTHEMOVE_TTF "fonts/onthemove.ttf"
#define PIXEL_TTF "fonts/I-pixel-u.ttf"
#define SPLASH_IMG "img/splash4.png"
#define PLAYER_IMG "img/player5.png"
#define PLAYER_RUNNING_IMG "img/player_running.png"
#define SNOOP_DOGG_ANIM "img/snoop.png"
#define SNOOP_DOGG_ANIM_REVERSE "img/snoop_reverse.png"
#define ILLUMINATI_IMG "img/illuminati.png"
#define GROUND_IMG "img/background_chunk3.png"
#define BACKGROUND_IMG "img/background_chunk.png"
#define FIRE_ANIM "img/fire.png"
#define SAW_IMG "img/saw.png"
#define DEAD_ANIM "img/smoke.png"
#define GAME_OVER_BG "img/gameover2.png"
#define GAME_OVER_BOARD "img/gameover_board.png"
#define LAVA_IMG "img/lava.png"
#define MISSILE_IMG "img/missile.png"
#define BASE_MISSILE_IMG "img/missile_base.png"
#define SPIKE_IMG "img/spikes.png"
#define SCORE_BG "img/score_background.png"
#define HEART_IMG "img/heart.png"
#define BLUR_EFFECT_PATH "src/blur.frag"
#define COIN_IMG "img/coin.png"
#define POLICE_CAR_IMG "img/police_car.png"
#define WHEEL_CAR_IMG "img/wheel.png"
#define MOON_IMG "img/moon.png"
#define PLATFORM_IMG "img/platform.png"


//GAME
#define GROUND_DEFAULT 100
#define NB_CHUNK 4 /*!< 4 chunks visibles en meme temps */
#define CHUNK_WIDTH (VIEW_WIDTH / NB_CHUNK)
#define CHUNK_HEIGHT VIEW_HEIGHT
#define CHUNK_PRELOAD 6 /*!< charge X chunks en mémoire */
#define DEAD_LINE_DEFAULT 100 /*!< Zone à partir de laquelle le joueur meurt par defaut */
#define FIRE_DEFAULT_POS 337
#define MIN_FIRE_POS -150 /*!< Lorsque le joueur avance, le feu recule mais ne va jamais plus loin que cette valeur */
#define MISSILE_DEFAULT_Y 100
#define MISSILE_DETECTION 1500 /*!< Distance à laquelle le missile detecte le joueur */
#define MISSILE_SPEED 10
#define MAX_FIRE_DIFFICULTY 18
#define MAX_BEST_SCORES 10 /*!< Nombre maximum de meilleurs score */
#define POLICE_SPEED 10

#endif // CONST_H
