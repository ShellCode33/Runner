#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <cassert>
#include <SFML/Graphics.hpp>
#include "button.h"
#include "screenwait.h"
#include "const.h"
#include "gamestate.h"
#include "timer.h"
#include "game.h"

class WindowRunner;

class GameOver : public ScreenWait
{
public:
    GameOver(WindowRunner *window, Game &game);
    ~GameOver();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void update();
    virtual void processEvent(sf::Event &event, State & state) override;
private:
    WindowRunner *window;
    Game & game;
    Timer timer; /*!< Utilisé pour l'apparation progressive du "tableau" de score/username etc... */

    sf::Texture board_texture;
    sf::Sprite board;

    sf::Font font;

    sf::Text pseudo_label;
    sf::Text score_label;

    sf::Text pseudo;
    sf::Text score;

    sf::RectangleShape cursor;
    Timer cursor_blink;
    bool cursor_visible;

    Button button_menu, button_playagain;

};

#endif // GAMEOVER_H
