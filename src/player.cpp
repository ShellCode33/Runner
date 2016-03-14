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

int Player::getHeight() const
{
  return height;
}

void Player::setHeight(int value)
{
  height = value;
}

void Player::setUsername(string value)
{
    username = value;
}


void Player::setPosition(pair<int, int> p)
{
  this->pos = p;
}

void Player::setVelocity(pair<int, int> v)
{
  this->velocity = v;
}

bool Player::inAir() const
{
  return (pos.first + height) < GROUND;
}

void Player::run()
{
  if(rightPressed && velocity.first < 7)
  {
    velocity.first += move_speed * acceleration * 1.0f / FRAMERATE;
  }
  else if(leftPressed && velocity.first > -7)
  {
    velocity.first += -move_speed * acceleration * 1.0f / FRAMERATE;
  }
  else
  {
    if(velocity.first < 0.0001 && velocity.first > -0.0001)
      velocity.first = 0;
    else
      velocity.first /= 1 + move_speed * 1.0f / FRAMERATE;
  }
}

void Player::jump()
{
  if(spacePressed && !inAir())
    velocity.second = -jump_speed;

  if(inAir())
  {
    velocity.first += GRAVITY * 1 / FRAMERATE;
    setPos(pos.first, pos.second + velocity.second * 1.0f / FRAMERATE);
  }
  else
    setPos(pos.first, GROUND - height);
}
