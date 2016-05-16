#include "platform_model.h"

using namespace std;

PlatformModel::PlatformModel() : Movable(0, 0, 0, 0), player_on_platform(false)
{}

PlatformModel::~PlatformModel()
{}

bool PlatformModel::checkCollision(Movable &m)
{
    return false;
}

void PlatformModel::action(Player &player)
{
    player.getModel()->setPosition(make_pair(player.getModel()->getX(), this->getY()));
}

bool PlatformModel::getPlayer_on_platform() const
{
    return this->player_on_platform;
}
