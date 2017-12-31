/*!
 * \file game_view.h
 * \class GameView
 * \brief
 * \author J3ry, ShellCode
 */

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <SFML/Graphics.hpp>
#include <list>
#include "gamestate.h"
#include "chunk.h"
#include "chunk_saw.h"
#include "chunk_special.h"
#include "animation.h"
#include "game_model.h"
#include "player.h"
#include "animation.h"

class WindowRunner;

class GameView : public sf::Drawable
{
public:
    GameView(WindowRunner& window, GameModel& model, Player &player, std::list<Chunk *> &chunks, std::list<Entity *> &entities);
    ~GameView();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(sf::Event & event);
    void update();
    void setGroundHeight(const int ground_height);
    int getGroundHeight() const;

    std::list<Chunk *> getChunks() const;
    std::list<Chunk *> getVisibleChunks() const;

    bool isPaused() const;
    void setPause(bool value);

private:
    WindowRunner& window;
    GameModel &game_model;

    sf::Texture fire_texture;
    Animation fire, fire2;

    sf::Texture lava_texture;
    Animation lava;

    Player &player;

    sf::Font font;

    sf::Texture texture_score;
    sf::Sprite score_background;
    sf::Text score_display;

    sf::Texture texture_life;
    sf::Sprite life_heart;
    sf::Text life_display;

    std::vector<Animation> lava_sprites; /*!< Vecteur contenant les différents carrés de lave après le feu qui poursuivent le joueur */
    Chunk *randomChunk() const; /*!< Retourne aléatoirement un chunk parmis tout ceux existant */

    std::list<Chunk *> &chunks;
    std::list<Entity *> &entities;

    bool pause; /*!< Si le jeu est en pause (avec la touche echap) alors le boolean est à true */

    sf::Texture texture_pause;
    sf::Shader blur; /*!< Shader utilisé pour le flou de la pause */
    sf::Image pause_img;
    sf::Sprite sprite_pause;
    sf::Text pause_text;

    /*!
     * \brief timer_police_circle1 et timer_police_circle2 permettent de faire clignoter la sirenne de la police et il y a 2 timers afin de créer un décalage entre les 2
     */
    Timer timer_police_circle1;
    Timer timer_police_circle2;
    bool display_police_alarm1;
    bool display_police_alarm2;
};

#endif //GAMEVIEW_H
