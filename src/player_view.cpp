#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(const string filename_player_img, Player& model) : Animation(100.0), player(model)
{
    this->player_texture.loadFromFile(filename_player_img);
    this->setTexture(this->player_texture);
    player.setHeight(49);
    player.setWidth(63);
    this->addClip(IntRect(0, 0, player.getWidth(), player.getHeight()));
    this->addClip(IntRect(64, 0, player.getWidth(), player.getHeight()));
    this->addClip(IntRect(127, 0, player.getWidth(), player.getHeight()));
    this->setAnimEnabled(false);
}

PlayerView::~PlayerView()
{

}

void PlayerView::update()
{
    Animation::update();
    this->setPosition(player.getX(), player.getY());
}

void PlayerView::processEvents(WindowRunner &window, Event &event)
{
    if(window.getState() == SURVIVAL || window.getState() == CAMPAIGN)
    {
        if(event.type == Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case Keyboard::Left:
                    player.leftPressed = true;
                    this->setOffset(0, 50);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Right:
                    player.rightPressed = true;
                    this->setOffset(0, 0);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Space:
                    player.spacePressed = true;
                    this->setAnimEnabled(false);
                    break;

                default: break;
            }
        }
        else if(event.type == Event::KeyReleased)
        {
            if((event.key.code == Keyboard::Left && !player.rightPressed) || (event.key.code == Keyboard::Right && !player.leftPressed))
                this->setAnimEnabled(false);

            switch(event.key.code)
            {
                case Keyboard::Left:
                    player.leftPressed = false;
                    break;

                case Keyboard::Right:
                    player.rightPressed = false;
                    break;

                case Keyboard::Space:
                    player.spacePressed = false;
                    this->setAnimEnabled(true);
                    break;

                default: break;
            }
        }
    }
}
