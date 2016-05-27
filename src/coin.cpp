#include "coin.h"

Coin::Coin(int relat_x, int relat_y, int width, int height) : model(relat_x, relat_y, width, height), view(model)
{}

Coin::~Coin()
{

}

CoinModel *Coin::getModel()
{
    return &this->model;
}

CoinView *Coin::getView()
{
    return &this->view;
}

void Coin::update()
{
    this->model.update();
    this->view.update();
}
