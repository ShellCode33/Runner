#include "gameover.h"
#include "window.h"

using namespace std;
using namespace sf;

GameOver::GameOver(WindowRunner *window) : ScreenWait(window, GAME_OVER_BG, GAME_OVER_TEXT), window(window), button_menu("MENU", MENU, 100, 450), button_playagain("PLAY AGAIN", SURVIVAL, 1320, 450) // position a faire en fonction de const
{
    assert(this->board_texture.loadFromFile(GAME_OVER_BOARD));
    this->board.setTexture(this->board_texture);
    this->board.setPosition((VIEW_WIDTH - this->board.getLocalBounds().width) / 2, VIEW_HEIGHT);


    this->timer = chrono::system_clock::now();
}

GameOver::~GameOver()
{

}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    ScreenWait::draw(target, states);
    target.draw(this->board);
    target.draw(this->button_menu, states);
    target.draw(this->button_playagain, states);
}

void GameOver::update()
{
    if(this->board.getPosition().y > (VIEW_HEIGHT - this->board.getLocalBounds().height) / 2)
    {
        auto diff = chrono::system_clock::now() - this->timer;
        auto msec = chrono::duration_cast<chrono::milliseconds>(diff);

        if(msec.count() > 20)
        {
            this->board.setPosition(this->board.getPosition().x, this->board.getPosition().y - 10);
            this->timer = chrono::system_clock::now();
        }
    }
}

void GameOver::processEvent(sf::Event &event, State &state)
{
    this->button_menu.processEvent(*this->window, event);
    this->button_playagain.processEvent(*this->window, event);

    if(state == GAME_OVER && event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
        this->window->setState(SURVIVAL);

    else if(state == GAME_OVER && event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        this->window->setState(MENU);
}
