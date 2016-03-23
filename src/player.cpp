#include "player.h"

Player::Player() : player_view(player_model)
{

}

Player::~Player()
{

}

void Player::update()
{
    player_model.applyForces();
    player_model.eventHandler();
    player_model.checkCollision();
}

PlayerView* Player::getView()
{
    return &player_view;
}

bool Player::needMoveBackground() const
{
    return player_model.needMoveBackground();
}

int Player::getBackgroundShift() const
{
    return player_model.getVelocity().first;
}

void Player::setMoveBackground(bool value)
{
    player_model.setMoveBackground(value);
}
