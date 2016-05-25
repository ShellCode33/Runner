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

/**STRING**/

#define TITLE_WINDOW "Super Weed Boy"
#define SPLASH_TEXT "Press <Space>"
#define GAME_OVER_TEXT " "

/*####################  PATH  ###################*/

/**BONUS**/

#define COIN_IMG "img/bonus/coin.png"
#define HEART_IMG "img/bonus/heart.png"
#define MAGNET_IMG "img/bonus/magnet.png"
#define MOON_IMG "img/bonus/moon.png"

/**CHUNKS**/

#define BACKGROUND_CHUNK_IMG "img/chunk/background_chunk.png"
#define BACKGROUND_CHUNK_IMG2 "img/chunk/background_chunk2.png"
#define GROUND_CHUNK_IMG "img/chunk/ground_chunk.png"
#define GROUND_CHUNK_IMG2 "img/chunk/ground_chunk2.png"

/**EFFECTS / ANIMATION**/

#define CURSOR_IMG "img/effects/cursor.png"
#define FIRE_IMG "img/effects/fire.png"
#define LAVA_IMG "img/effects/lava.png"
#define SMOKE_IMG "img/effects/smoke.png"
#define SNOOP_DOGG_IMG "img/effects/snoop.png"
#define SNOOP_DOGG_REVERSE_IMG "img/effects/snoop_reverse.png"
#define BLUR_EFFECT_PATH "img/effects/blur.frag"

/**IMAGES**/

#define BUTTON_IMG "img/images/button.png"
#define GAMEOVER_BACKGROUND_IMG "img/images/gameover_background.png"
#define GAMEOVER_BOARD_IMG "img/images/gameover_board.png"
#define HIGHSCORES_BACKGROUND_IMG "img/images/highscores_bg.jpg"
#define ILLUMINATI_IMG "img/images/illuminati.png"
#define MENU_BACKGROUND_IMG "img/images/menu_background.png"
#define SCORE_BOARD_IMG "img/images/score_background.png"
#define SPLASH_BACKGROUND_IMG "img/images/splash_background.png"
#define OPTION_BACKGROUND_IMG "img/images/option_background.png"
#define FLAG_FR_IMG "img/images/fr.png"
#define FLAG_EN_IMG "img/images/en.png"
#define FLAG_ES_IMG "img/images/es.png"

/**OBSTACLES**/

#define MISSILE_IMG "img/obstacles/missile.png"
#define MISSILE_BASE_IMG "img/obstacles/missile_base.png"
#define PLATFORM_IMG "img/obstacles/platform.png"
#define POLICE_CAR_IMG "img/obstacles/police_car.png"
#define SAW_IMG "img/obstacles/saw.png"
#define SPIKE_IMG "img/obstacles/spikes.png"
#define WHEEL_IMG "img/obstacles/wheel.png"

/**PLAYER**/

#define PLAYER_WALKING_IMG "img/player/player_walking.png"
#define PLAYER_RUNNING_IMG "img/player/player_running.png"
#define PLAYER_JUMPING_IMG "img/player/player_jumping.png"

/**FONT**/

#define ONTHEMOVE_TTF "fonts/onthemove.ttf"
#define PIXEL_TTF "fonts/I-pixel-u.ttf"

/*###############################################*/


/**GAME CONST**/

#define GROUND_DEFAULT 100
#define NB_CHUNK 4 /*!< 4 chunks visibles en meme temps */
#define CHUNK_WIDTH (VIEW_WIDTH / NB_CHUNK)
#define CHUNK_HEIGHT VIEW_HEIGHT
#define CHUNK_PRELOAD 6 /*!< charge X chunks en mémoire */
#define DEAD_LINE_DEFAULT 100 /*!< Zone à partir de laquelle le joueur meurt par defaut */
#define FIRE_DEFAULT_POS 337
#define MIN_FIRE_POS -150 /*!< Lorsque le joueur avance, le feu recule mais ne va jamais plus loin que cette valeur */
#define MISSILE_DEFAULT_Y 100
#define MISSILE_DETECTION 800 /*!< Distance à laquelle le missile detecte le joueur */
#define MISSILE_SPEED 10
#define MAX_FIRE_DIFFICULTY 18
#define MAX_BEST_SCORES 10 /*!< Nombre maximum de meilleurs score */
#define POLICE_SPEED 10
#define COIN_SPEED_MAGNET 2
#define NB_THEMES 2
#endif // CONST_H
