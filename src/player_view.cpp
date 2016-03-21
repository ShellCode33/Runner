#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(const string filename_player_img) : Animation(3.0)
{
    this->player_texture.loadFromFile(filename_player_img);
    this->setTexture(this->player_texture);
    this->setPosition(500, 500);
    this->addClip(IntRect(0, 0, 63, 49));
    this->addClip(IntRect(64, 0, 63, 49));
    this->addClip(IntRect(127, 0, 63, 49));

    player.setHeight(this->getLocalBounds().height);
}

PlayerView::~PlayerView()
{

}

void PlayerView::update()
{
    Animation::update();
    player.applyForces();
    player.eventHandler();
    player.checkCollision();
    player.setPos(player.getPos());
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
                    break;

                case Keyboard::Right:
                    player.rightPressed = true;
                    break;

                case Keyboard::Space:
                    player.spacePressed = true;
                    break;

                default: break;
            }
        }
        else if(event.type == Event::KeyReleased)
        {
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
                    break;

                default: break;
            }
        }
    }
}
