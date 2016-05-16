#include "platform.h"

Platform::Platform() :  model(), view(model)
{}

Platform::~Platform()
{

}

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states)
{
    target.draw(this->view, states);
}

void Platform::action(Player &player)
{
    this->model.action(player);
}

bool Platform::checkCollision(Movable &m)
{
    return this->model.checkCollision(m);
}

