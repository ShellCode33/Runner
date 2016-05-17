#include "police.h"

Police::Police() : view(model)
{

}

Police::~Police()
{

}

void Police::update()
{
    this->model.update();
    this->view.update();
}

PoliceModel* Police::getModel()
{
    return &this->model;
}

PoliceView* Police::getView()
{
    return &this->view;
}

void Police::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->view, states);
}

void Police::action(Player &player)
{
    player.getModel()->setLife(player.getModel()->getLife() - 80);
    this->model.setCollision(true);
}

bool Police::checkCollision(Movable &m) const
{
    return this->model.checkCollision(m);
}
