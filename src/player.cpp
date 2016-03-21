#include "player.h"

using namespace std;

Player::Player(const string username) : leftPressed(false), rightPressed(false), spacePressed(false), max_fall(5), run_acc(.20f), max_run(2.5f), jump_acc(-1), jumpframe(30), jump_counter(0)
{
    this->username = username;
    this->setVelocity(make_pair(0, 0));
    this->setPos(make_pair(VIEW_WIDTH / 2, 0));
    this->setGravity(make_pair(0, .5f));
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

void Player::setVelocity(pair<int, int> v)
{
    this->velocity = v;
}

void Player::eventHandler()
{
    const bool onGround = pos.second > (VIEW_HEIGHT - height - GROUND);

    if(leftPressed)
<<<<<<< HEAD
    {velocity.first -= run_acc;}
    else if(rightPressed)
    {velocity.first += run_acc;}
    else
    {velocity.first *= 0.9;}
=======
        velocity.first -= run_acc;

    else if(rightPressed)
        velocity.first += run_acc;

    else
        velocity.first *= 0.9;
>>>>>>> c15d4d2c15fc61424b960718c8a848b2a66c122f

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
<<<<<<< HEAD
    {jump_counter = 0;}
=======
        jump_counter = 0;
>>>>>>> c15d4d2c15fc61424b960718c8a848b2a66c122f

}

void Player::checkCollision()
{
<<<<<<< HEAD
    if(pos.second > VIEW_HEIGHT - height / 2)
    {velocity.second = 0; pos.second = VIEW_HEIGHT - height / 2;}
    if(pos.first < 0)
    {velocity.first = 0; pos.first = 0;}
    else if(pos.first > VIEW_WIDTH - 63)
    {velocity.first = 0; pos.first = VIEW_WIDTH - 63;}
=======
    if(pos.second > VIEW_HEIGHT - height - GROUND)
        {velocity.second = 0; pos.second = VIEW_HEIGHT - height - GROUND;}
    if(pos.first < 0)
        {velocity.first = 0; pos.first = 0;}
    else if(pos.first > VIEW_WIDTH - width)
        {velocity.first = 0; pos.first = VIEW_WIDTH - width;}
>>>>>>> c15d4d2c15fc61424b960718c8a848b2a66c122f
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

int Player::getWidth() const
{
    return width;
}

void Player::setWidth(int value)
{
    width = value;
}

pair<float, float> operator+=(pair<float, float>& a, const pair<float, float>& b)
{
    a.first += b.first;
<<<<<<< HEAD
    a.second += b.second;
    return a;
=======
 a.second += b.second;
 return a;
>>>>>>> c15d4d2c15fc61424b960718c8a848b2a66c122f
}
