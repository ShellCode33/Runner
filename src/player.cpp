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


void Player::setPosition(pair<int, int> p)
{
  this->pos = p;
}

void Player::setVelocity(pair<int, int> v)
{
  this->velocity = v;
}

/*bool inAir(const int ground, int height_object) const
{
  return this->pos.y + height_object < ground;
}*/

void Player::run(pair<int, int> v, const float move_speed, const float acceleration, const int framerate)
{
  if(rightPressed && v.first < 7)
  {
    v.first += move_speed * acceleration * 1.0f / framerate;
  }
  else if(leftPressed && v.first > -7)
  {
    v.first += -move_speed * acceleration * 1.0f / framerate;
  }
  else
  {
    if(v.first < 0.0001 && v.first > -0.0001)
      v.first = 0;
    else
      v.first /= 1 + move_speed * 1.0f / framerate;
  }
}

void Player::jump(pair<int, int> v, const float jump_speed, const float gravity, const int framerate, pair<int, int> p, const int ground, const int height_object)
{
  if(spacePressed /*&& !inAir*/)
    v.second = -jump_speed;

  /*if(inAir)
  {
    v.y += gravity * 1 / framerate;
    setPosition(p.x, p.y + v.y * 1.0f / framerate);
  }
  else
    setPosition(p.x, ground - height_object);*/
}
