#include "coin_view.h"

using namespace std;
using namespace sf;

CoinView::CoinView(CoinModel &model) : Animation(100.0), model(model)
{
    assert(this->coin_texture.loadFromFile("Coin_IMG"));
    this->setTexture(this->coin_texture);

    this->model.setWidth(30);
    this->model.setHeight(35);

    for(unsigned int i = 0; i < 8; i++)
        this->addClip(IntRect(model.getWidth() * i, 0, model.getWidth(), model.getHeight()));
    this->setAnimEnabled(true);
}

CoinView::~CoinView()
{

}

void CoinView::update()
{

}