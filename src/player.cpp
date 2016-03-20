#include "player.h"

using namespace std;

Player::Player(const string username) : max_fall(5), run_acc(.20f), max_run(2.5f), jump_acc(-1), jumpframe(10), jump_counter(0)
{
    this->username = username;
    this->setVelocity({0, 0});
    this->setPos(50, 50);
    this->setGravity({0, .5f});
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

void Player::run()
{
    if(leftPressed)
        velocity.first -= run_acc;
    else if(rightPressed)
        velocity.first += run_acc;
    else
        velocity.first *= 0.9;
}

void Player::jump()
{
    const bool onGround = pos.second > 400;

    if(spacePressed)
    {
        if(onGround)
        {
            velocity.second += jump_acc * 2;
            jump_counter = jumpframe;
        }
        else if(jump_counter > 0)
        {
            velocity.second += jump_acc;
            jump_counter--;
        }
    }
    else
        jump_counter = 0;
}

void Player::checkCollision()
{
    if(pos.second > 400)
        {velocity.second = 0; pos.second = 400;}
    if(pos.first < 0)
        {velocity.first = 0; pos.first = 0;}
    else if(pos.first > 1000)
        {velocity.first = 0; pos.first = 1000;}
}

void Player::applyForces()
{
    pos += velocity;
    velocity += gravity;
}

std::pair<float, float> Player::getGravity() const
{
    return gravity;
}

void Player::setGravity(const std::pair<float, float> &value)
{
    gravity = value;
}

std::pair<float, float> Player::getPos() const
{
    return pos;
}

pair<float, float> operator+=(pair<float, float>& a, const pair<float, float>& b)
{
 a.first += b.first;
 a.second += b.second;
 return a;
}
