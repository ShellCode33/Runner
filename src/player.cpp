#include "player.h"

using namespace std;

Player::Player(const string username)
{
    this->username = username;
}

Player::~Player()
{

}

unsigned int Player::getScore() const
{
    return score;
}

void Player::setScore(unsigned int value)
{
    score = value;
}

unsigned short Player::getLife() const
{
    return life;
}

void Player::setLife(unsigned short value)
{
    life = value;
}

void Player::setUsername(string value)
{
    username = value;
}
