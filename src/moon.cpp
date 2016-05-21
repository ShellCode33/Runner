#include "moon.h"

Moon::Moon(int relat_x, int relat_y, int width, int height) : model(relat_x, relat_y, width, height), view(model)
{}

Moon::~Moon()
{}

void Moon::update()
{
    this->model.update();
    this->view.update();
}

MoonView *Moon::getView()
{
    return &this->view;
}

MoonModel *Moon::getModel()
{
    return &this->model;
}
