#include "missile_seeker.h"

using namespace std;

MissileSeeker::MissileSeeker(Player &player) : player(player), model(*player.getModel()), view(model)
{

}

MissileSeeker::~MissileSeeker()
{

}

void MissileSeeker::update()
{
    this->model.update();
    this->view.update();
}

MissileModel *MissileSeeker::getModel()
{
    return &this->model;
}

MissileView *MissileSeeker::getView()
{
    return &this->view;
}

void MissileSeeker::draw(sf::RenderTarget &target, sf::RenderStates states)
{
    target.draw(this->view, states);
}

void MissileSeeker::action(Player &player)
{
    this->model.action(player);
}

bool MissileSeeker::checkCollision(Movable &m)
{
    return this->model.checkCollision(m);
}
