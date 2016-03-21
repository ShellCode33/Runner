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


    void setVelocity(std::pair<int, int> v);

    void run();
    void jump();

    void checkCollision();
    void applyForces();

    bool leftPressed, rightPressed, spacePressed;

    std::pair<float, float> getGravity() const;
    void setGravity(const std::pair<float, float> &value);

private:
    std::string username;
    unsigned int score;
    unsigned short life;

    float max_fall;
    float run_acc;
    float max_run;
    float jump_acc;

    unsigned char jumpframe;

    unsigned char jump_counter;

    int height;

    std::pair<float, float> gravity;
    //std::pair<float, float> pos;
    std::pair<float, float> velocity;
};

std::pair<float, float> operator+=(std::pair<float, float>& a, const std::pair<float, float>& b);

#endif // PLAYER_H
