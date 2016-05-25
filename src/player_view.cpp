#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(PlayerModel &model) : Animation(100.0), player_model(model), smoke(50.0)
{
    assert(this->player_texture.loadFromFile(PLAYER_WALKING_IMG));
    this->setTexture(this->player_texture);

    //Liste d'initialisation impossible car sinon, bug avec les getWidth et getHeight qui suivent
    this->player_model.setHeight(46);
    this->player_model.setWidth(50);

    for(int i = 0; i< 4; i++)
        this->addClip(IntRect(50 * i, 0, player_model.getWidth(), player_model.getHeight()));
    this->setAnimEnabled(false);


    assert(this->smoke_texture.loadFromFile(SMOKE_IMG));
    this->smoke.setTexture(this->smoke_texture);

    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 2; j++)
            this->smoke.addClip(IntRect(256*j, 256*i, 256, 256));

    this->smoke.setOrigin(this->smoke.getLocalBounds().width / 2, this->smoke.getLocalBounds().height / 2);
}

PlayerView::~PlayerView()
{

}

void PlayerView::update()
{
    if(!this->player_model.isDead())
    {
        Animation::update();
        this->setPosition(player_model.getX(), player_model.getY());
        this->smoke.setPosition(this->getPosition());
    }
}

Animation* PlayerView::getDeadAnim()
{
    return &this->smoke;
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
                    this->setOffset(0, 46);
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

                    if(this->player_model.leftPressed || this->player_model.rightPressed)
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
