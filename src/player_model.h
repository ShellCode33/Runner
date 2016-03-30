/*!
 * \file player_model.h
 * \class PlayerModel
 * \brief Partie modele du joueur, contient l'ensemble des calculs le concernant
 * \author Jérémie
 */

#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <iostream>
#include "movable.h"
#include "utils.h"

enum Direction
{
    LEFT,
    RIGHT
};

class PlayerModel : public Movable
{
public:
    PlayerModel(const std::string username="unknown");
    ~PlayerModel();
    std::string getUsername();

    unsigned int getScore() const;
    void setScore(unsigned int value);

    unsigned short getLife() const;
    void setLife(unsigned short value);

    std::string getUsername() const;
    void setUsername(std::string value);

    std::pair<int, int> getVelocity() const;
    void setVelocity(std::pair<int, int> v);

    void eventHandler();

    void checkCollision();
    void applyForces();

    bool leftPressed, rightPressed, spacePressed, shiftPressed;

    std::pair<float, float> getGravity() const;
    void setGravity(const std::pair<float, float> &value);

    bool needMoveBackground() const;
    void setMoveBackground(bool value);
    int getSavedVelocityX() const;

    void setVelocityX(float value);
    void setVelocityY(float value);

    bool isDead() const;

    int getDeadLine() const;
    void setDeadLine(int value);

private:
    std::string username;
    unsigned short life;

    float walk_acc;
    float run_acc;
    float max_walk;
    float max_run;
    float jump_acc;
    float max_fall;

    float decelaration;

    int jumpframe;
    int jump_counter;

    std::pair<float, float> gravity;
    std::pair<float, float> velocity;

    bool move_background; /*!< utilisé lorsque le joueur essaye d'aller au delà de la limite imposée afin de faire "avancer" le background */
    int dead_line; /*!< Utilisé pour savoir où se situe le feu et tuer le joueur si celui-ci est dedans */
};

std::pair<float, float> operator+=(std::pair<float, float>& a, const std::pair<float, float>& b);

#endif // PLAYERMODEL_H
