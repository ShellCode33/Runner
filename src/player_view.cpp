#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(PlayerModel &model) : Animation(100.0), player_model(model)
{
    assert(this->player_texture.loadFromFile(PLAYER_IMG));
    this->setTexture(this->player_texture);

    //Liste d'initialisation impossible car sinon, bug avec les getWidth et getHeight qui suivent
    this->player_model.setHeight(49);
    this->player_model.setWidth(63);

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
                    this->player_model.leftPressed = true;
                    this->player_model.rightPressed = false;
                    this->setOffset(0, 50);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Right:
                    this->player_model.rightPressed = true;
                    this->player_model.leftPressed = false;
                    this->setOffset(0, 0);
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::Space:
                    this->player_model.spacePressed = true;
                    this->setAnimEnabled(false);
                    break;

                case Keyboard::LShift:
                    this->player_model.shiftPressed = true;
                    break;

                default: break;
            }
        }
        else if(event.type == Event::KeyReleased)
        {
            if((event.key.code == Keyboard::Left && !this->player_model.rightPressed) || (event.key.code == Keyboard::Right && !this->player_model.leftPressed))
                this->setAnimEnabled(false);

            switch(event.key.code)
            {
                case Keyboard::Left:
                    this->player_model.leftPressed = false;
                    break;

                case Keyboard::Right:
                    this->player_model.rightPressed = false;
                    break;

                case Keyboard::Space:
                    this->player_model.spacePressed = false;
                    this->setAnimEnabled(true);
                    break;

                case Keyboard::LShift:
                    this->player_model.shiftPressed = false;
                    break;

                default: break;
            }
        }
    }
}
