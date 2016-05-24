#include "platform_model.h"
#include "game_model.h"

using namespace std;

PlatformModel::PlatformModel(int relat_x, int relat_y, int width, int height) : Obstacle(relat_x, relat_y, width, height), player_on_platform(false)
{}

PlatformModel::~PlatformModel()
{}

bool PlatformModel::checkCollision(Movable &m) const
{
    if(this->getPosition().second <= m.getPosition().second + m.getHeight())
    {
        AABB platformRect, playerRect;

        platformRect.x = this->getX();
        platformRect.y = this->getY();
        platformRect.w = this->getWidth();
        platformRect.h = this->getHeight();

        playerRect.x = m.getX();
        playerRect.y = m.getY();
        playerRect.w = m.getWidth();
        playerRect.h = m.getHeight();

        return Collision::AABBintersectAABB(platformRect, playerRect);
    }
    return false;
}

void PlatformModel::action(GameModel &game)
{
    cout << "player on platform" << endl;
    game.getPlayer().getModel()->setPosition(make_pair(game.getPlayer().getModel()->getX(), this->getY() - game.getPlayer().getModel()->getHeight()));
}

void PlatformModel::update()
{

}

bool PlatformModel::getPlayer_on_platform() const
{
    return this->player_on_platform;
}
