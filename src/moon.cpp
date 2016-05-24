#include "moon.h"

using namespace std;

Moon::Moon(PlayerModel &player, int relat_x, int relat_y, int width, int height) : Effect(player), model(relat_x, relat_y, width, height), view(model)
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

void Moon::start(PlayerModel &player)
{
    player.setGravity(make_pair(0, .2f));
}

void Moon::stop(PlayerModel &player)
{
    player.setGravity(make_pair(0, .5f));
}
