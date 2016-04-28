#include "spike.h"

Spike::Spike(int relat_x, int relat_y, int width, int height) : model(relat_x, relat_y, width, height), view(model)
{

}

Spike::~Spike()
{

}

SpikeView *Spike::getView()
{
    return &this->view;
}

SpikeModel *Spike::getModel()
{
    return &this->model;
}

void Spike::update()
{
    this->model.update();
    this->view.update();
}
