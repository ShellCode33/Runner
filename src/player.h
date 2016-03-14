#ifndef PLAYER_H
#define PLAYER_H

#define GRAVITY 9.8f

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

    int getHeight() const;
    void setHeight(int value);

    std::string getUsername() const;
    void setUsername(std::string value);


    void setPosition(std::pair<int, int> p);
    void setVelocity(std::pair<int, int> v);

    bool inAir() const;
    void run();
    void jump();

    bool leftPressed, rightPressed, spacePressed;

private:
    std::string username;
    unsigned int score;
    unsigned short life;

    float move_speed;
    float jump_speed;
    float acceleration;

    int height;

    std::pair<float, float> pos;
    std::pair<float, float> velocity;
    Direction direction;
};

#endif // PLAYER_H
