#include "player.h"

Player::Player() : player_view(player_model)
{

}

Player::~Player()
{

}

void Player::update()
{
    this->player_model.applyForces();
    this->player_model.eventHandler();
    this->player_model.checkCollision();
}

PlayerView* Player::getView()
{
    return &this->player_view;
}

bool Player::needMoveBackground() const
{
    return this->player_model.needMoveBackground();
}

int Player::getBackgroundShift() const
{
    return this->player_model.getVelocity().first;
}

void Player::setMoveBackground(bool value)
{
    this->player_model.setMoveBackground(value);
}
