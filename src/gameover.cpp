#include "gameover.h"
#include "window.h"

using namespace std;
using namespace sf;

GameOver::GameOver(WindowRunner *window, Game &game) : ScreenWait(GAME_OVER_BG, GAME_OVER_TEXT), window(window), game(game), timer(20), cursor_blink(500), cursor_visible(false), button_menu("MENU", MENU, 0, 0), button_playagain("PLAY AGAIN", SURVIVAL, 0, 0)
{
    assert(this->board_texture.loadFromFile(GAME_OVER_BOARD));
    this->board.setTexture(this->board_texture);
    this->board.setPosition((VIEW_WIDTH - this->board.getLocalBounds().width) / 2, VIEW_HEIGHT);

    assert(this->font.loadFromFile(ONTHEMOVE_TTF));
    this->pseudo.setFont(this->font);
    this->pseudo.setCharacterSize(40);
    this->pseudo.setColor(Color(176, 33, 37, 255));
    this->pseudo.setStyle(Text::Bold);
    this->pseudo.setPosition(VIEW_WIDTH / 2, VIEW_HEIGHT + 103);

    this->score.setFont(this->font);
    this->score.setCharacterSize(40);
    this->score.setColor(Color(176, 33, 37, 255));
    this->score.setStyle(Text::Bold);
    this->score.setPosition(VIEW_WIDTH / 2, VIEW_HEIGHT + 176);

    this->cursor.setPosition(VIEW_WIDTH / 2 + this->pseudo.getLocalBounds().width, VIEW_HEIGHT + 108);
    this->cursor.setSize(Vector2f(2, 40));

    this->button_menu.setPosition((VIEW_WIDTH - this->button_playagain.getSize().first) / 2, VIEW_HEIGHT + 250);
    this->button_playagain.setPosition((VIEW_WIDTH - this->button_playagain.getSize().first) / 2, VIEW_HEIGHT + 350);

    this->timer.begin();
    this->cursor_blink.begin();
}

GameOver::~GameOver()
{

}

void GameOver::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    ScreenWait::draw(target, states);
    target.draw(this->board, states);
    target.draw(this->pseudo, states);
    target.draw(this->cursor, states);
    target.draw(this->score, states);
    target.draw(this->button_menu, states);
    target.draw(this->button_playagain, states);
}

void GameOver::update()
{
    this->pseudo.setString(game.getModel()->getPseudo());
    this->score.setString(to_string(game.getModel()->getScore()));

    if(this->board.getPosition().y > (VIEW_HEIGHT - this->board.getLocalBounds().height) / 2)
    {
        if(this->timer.isFinish())
        {
            this->board.setPosition(this->board.getPosition().x, this->board.getPosition().y - 10);
            this->pseudo.setPosition(this->pseudo.getPosition().x, this->pseudo.getPosition().y - 10);
            this->cursor.setPosition(VIEW_WIDTH / 2 + this->pseudo.getLocalBounds().width, this->cursor.getPosition().y - 10);
            this->score.setPosition(this->score.getPosition().x, this->score.getPosition().y - 10);
            this->button_menu.setPosition(this->button_menu.getPosition().first, this->button_menu.getPosition().second - 10);
            this->button_playagain.setPosition(this->button_playagain.getPosition().first, this->button_playagain.getPosition().second - 10);

            this->timer.reset();
        }
    }

    else
    {
        if(this->cursor_blink.isFinish())
        {
            if(this->cursor_visible)
                this->cursor.setFillColor(Color(255, 255, 255, 255));
            else
                this->cursor.setFillColor(Color(255, 255, 255, 0));

            this->cursor_visible = !this->cursor_visible;
            this->cursor_blink.reset();
        }

        this->cursor.setPosition(VIEW_WIDTH / 2 + this->pseudo.getLocalBounds().width, this->cursor.getPosition().y);
    }
}

void GameOver::processEvent(sf::Event &event, State &state)
{
    this->button_menu.processEvent(*this->window, event);
    this->button_playagain.processEvent(*this->window, event);

    string current_pseudo = this->game.getModel()->getPseudo();

    if(state == GAME_OVER && event.type == Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case Keyboard::Return:
            case Keyboard::Space:
                this->window->setState(SURVIVAL);
                break;

            case Keyboard::Escape:
                this->window->setState(MENU);
                break;

            case Keyboard::BackSpace:
                if(current_pseudo.size() > 0)
                {
                    current_pseudo.erase(current_pseudo.size()-1);
                    this->game.getModel()->setPseudo(current_pseudo);
                }
                break;

            default: break;
        }

        //Ajout de la lettre dans le pseudo
        if(current_pseudo.size() <= 10 && event.key.code >= 0 && event.key.code <= 25)
        {
            char c;

            if(event.key.shift)
                c = (char) event.key.code + 65; //ascii value
            else
                c = (char) event.key.code + 97; //ascii value

            this->game.getModel()->setPseudo(current_pseudo + c);
        }
    }
}
