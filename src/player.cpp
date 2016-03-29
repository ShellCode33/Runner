#include "player.h"

Player::Player() : player_view(player_model)
{

}

Player::~Player()
{

}

void Player::update()
{
    if(!this->player_model.isDead())
    {
        this->player_model.applyForces();
        this->player_model.eventHandler();
        this->player_model.checkCollision();
    }
}

PlayerView* Player::getView()
{
    return &this->player_view;
}

PlayerModel* Player::getModel()
{
    return &this->player_model;
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

void Player::kill()
{
    this->player_model.setLife(0);
}
