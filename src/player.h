#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
public:
    Player(std::string username="unknown");
    ~Player();
    std::string getUsername();

private:
    std::string username;
    unsigned int score;
    unsigned short life;

};

#endif // PLAYER_H
