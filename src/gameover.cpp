#include "gameover.h"
#include "window.h"

using namespace std;
using namespace sf;

GameOver::GameOver(WindowRunner *window) : ScreenWait(window, GAME_OVER_BG, GAME_OVER_TEXT), window(window), timer(20), button_menu("MENU", MENU, 100, 450), button_playagain("PLAY AGAIN", SURVIVAL, 1320, 450)
{
    assert(this->board_texture.loadFromFile(GAME_OVER_BOARD));
    this->board.setTexture(this->board_texture);
    this->board.setPosition((VIEW_WIDTH - this->board.getLocalBounds().width) / 2, VIEW_HEIGHT);


    this->timer.begin();
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
        if(this->timer.isFinish())
        {
            this->board.setPosition(this->board.getPosition().x, this->board.getPosition().y - 10);
            this->timer.reset();
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
