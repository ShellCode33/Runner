#include "magnet.h"

Magnet::Magnet(PlayerModel &player, int relat_x, int relat_y, int width, int height) : Effect(player), model(player, relat_x, relat_y, width, height), view(model)
{

}

void Magnet::start(PlayerModel &player)
{
    this->model.start(player);
}

void Magnet::stop(PlayerModel &player)
{
    this->model.stop(player);
}

void Magnet::update()
{
    this->model.update();
    this->view.update();
}

MagnetModel *Magnet::getModel()
{
    return &this->model;
}

MagnetView *Magnet::getView()
{
    return &this->view;
}
