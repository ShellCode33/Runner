#include "heart.h"

Heart::Heart(int relat_x, int relat_y, int width, int height) : model(relat_x, relat_y, width, height), view(model)
{

}

Heart::~Heart()
{

}

void Heart::update()
{
    this->model.update();
    this->view.update();
}

HeartModel *Heart::getModel()
{
    return &this->model;
}

HeartView *Heart::getView()
{
    return &this->view;
}
