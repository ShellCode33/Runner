#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <cassert>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "button.h"
#include "screenwait.h"
#include "const.h"
#include "gamestate.h"

class WindowRunner;

class GameOver : public ScreenWait
{
public:
    GameOver(WindowRunner *window);
    ~GameOver();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void update();
    virtual void processEvent(sf::Event &event, State & state) override;
private:
    WindowRunner *window;
    std::chrono::high_resolution_clock::time_point timer; /*!< Utilisé pour l'apparation progressive du "tableau" de score/username etc... */
    sf::Texture board_texture;
    sf::Sprite board;
    std::string input_username;
    Button button_menu, button_playagain;

};

#endif // GAMEOVER_H
