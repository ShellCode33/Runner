#include "saw.h"

Saw::Saw(int relat_x, int relat_y, int width, int height) : model(relat_x, relat_y, width, height), view(model)
{

}

Saw::~Saw()
{

}

SawModel* Saw::getModel()
{
    return &this->model;
}

SawView* Saw::getView()
{
    return &this->view;
}

void Saw::update()
{
    this->model.update();
    this->view.update();
}
