#include "player_view.h"
#include "window.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(PlayerModel &model) : Animation(100.0), player_model(model), smoke(50.0)
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

    assert(this->smoke_texture.loadFromFile(DEAD_ANIM));
    this->smoke.setTexture(this->smoke_texture);

    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 2; j++)
            this->smoke.addClip(IntRect(512*j, 512*i, 512, 512));
}

PlayerView::~PlayerView()
{

}

void PlayerView::update()
{
    //tester si le joueur est mort et faire un playOneTime
    Animation::update();
    this->setPosition(player_model.getX(), player_model.getY());
}

bool PlayerView::deadAnim()
{
    this->setTexture(this->smoke_texture);
    this->removeClips();

    //TESTS : A SUPPRIMER
    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 2; j++)
            this->addClip(IntRect(512*j, 512*i, 512, 512));

    /*
    this->smoke.setPosition(this->getPosition());
    return this->smoke.playOneTime();
    */
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
