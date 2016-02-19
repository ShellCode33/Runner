#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
public:
    Player(std::string username="unknown");
    ~Player();
    std::string getUsername();

    unsigned int getScore() const;
    void setScore(unsigned int value);

    unsigned short getLife() const;
    void setLife(unsigned short value);

    std::string getUsername() const;
    void setUsername(std::string value);

private:
    std::string username;
    unsigned int score;
    unsigned short life;
};

#endif // PLAYER_H
