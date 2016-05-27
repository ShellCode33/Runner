#include "coin_view.h"

using namespace std;
using namespace sf;

CoinView::CoinView(CoinModel &model) : Animation(100.0), model(model), sound_played(false)
{
    this->sound.load(COIN_TAKEN_SNG);
    this->sound.setVolume(50);

    assert(this->coin_texture.loadFromFile(COIN_IMG));
    this->setTexture(this->coin_texture);

    this->model.setWidth(32);
    this->model.setHeight(32);

    for(unsigned int i = 0; i < 6; i++)
        this->addClip(IntRect(model.getWidth() * i, 0, model.getWidth(), model.getHeight()));

    this->setAnimEnabled(true);
}

CoinView::~CoinView()
{

}

void CoinView::update()
{
    if(!this->model.isTaken())
    {
        Animation::update();
        this->setPosition(this->model.getX(), this->model.getY());
    }

    else if(!this->sound_played)
    {
        this->sound.play();
        this->sound_played = true;
    }
}
