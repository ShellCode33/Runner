#include "player.h"

using namespace std;

Player::Player(string username)
{
    this->username = username;
}

Player::~Player()
{

}

string Player::getUsername()
{
    return username;
}
