#include "platform.h"

Platform::Platform(int relat_x, int relat_y, int width, int height) :  model(relat_x, relat_y, width, height), view(model)
{}

Platform::~Platform()
{}

void Platform::action(GameModel &game)
{
    this->model.action(game);
}

bool Platform::checkCollision(Movable &m) const
{
    return this->model.checkCollision(m);
}

void Platform::update()
{
    this->model.update();
    this->view.update();
}

PlatformModel *Platform::getModel()
{
    return &this->model;
}

PlatformView *Platform::getView()
{
    return &this->view;
}

