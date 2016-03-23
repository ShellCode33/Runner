#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(PlayerModel &model) : Animation(100.0), player_model(model)
{
    this->player_texture.loadFromFile(PLAYER_IMG);
    this->setTexture(this->player_texture);
    player_model.setHeight(49);
    player_model.setWidth(63);
    this->addClip(IntRect(0, 0, player_model.getWidth(), player_model.getHeight()));
    this->addClip(IntRect(64, 0, player_model.getWidth(), player_model.getHeight()));
    this->addClip(IntRect(127, 0, player_model.getWidth(), player_model.getHeight()));
    this->setAnimEnabled(false);
}

PlayerView::~PlayerView()
{

}

void PlayerView::update()
{
    Animation::update();
    this->setPosition(player_model.getX(), player_model.getY());
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
                    player_model.leftPressed = true;
                    this->setOffset(0, 50);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Right:
                    player_model.rightPressed = true;
                    this->setOffset(0, 0);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Space:
                    player_model.spacePressed = true;
                    this->setAnimEnabled(false);
                    break;

                default: break;
            }
        }
        else if(event.type == Event::KeyReleased)
        {
            if((event.key.code == Keyboard::Left && !player_model.rightPressed) || (event.key.code == Keyboard::Right && !player_model.leftPressed))
                this->setAnimEnabled(false);

            switch(event.key.code)
            {
                case Keyboard::Left:
                    player_model.leftPressed = false;
                    break;

                case Keyboard::Right:
                    player_model.rightPressed = false;
                    break;

                case Keyboard::Space:
                    player_model.spacePressed = false;
                    this->setAnimEnabled(true);
                    break;

                default: break;
            }
        }
    }
}
