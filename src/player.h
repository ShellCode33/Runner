#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "movable.h"

enum Direction
{
  LEFT,
  RIGHT
};

class Player : public Movable
{
public:
    Player(const std::string username="unknown");
    ~Player();
    std::string getUsername();

    unsigned int getScore() const;
    void setScore(unsigned int value);

    unsigned short getLife() const;
    void setLife(unsigned short value);

    std::string getUsername() const;
    void setUsername(std::string value);


    void setPosition(std::pair<int, int> p);
    void setVelocity(std::pair<int, int> v);

    //bool inAir(const int ground, int height_object) const
    void run(std::pair<int, int> v, const float move_speed, const float acceleration, const int framerate);
    void jump(std::pair<int, int> v, const float jump_speed, const float gravity, const int framerate, std::pair<int, int> p, const int ground, const int height_object);

    bool leftPressed, rightPressed, spacePressed;


private:
    std::string username;
    unsigned int score;
    unsigned short life;

    std::pair<int, int> pos;
    std::pair<int, int> velocity;
    Direction direction;
};

#endif // PLAYER_H
