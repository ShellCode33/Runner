#include "player_model.h"

using namespace std;

PlayerModel::PlayerModel(const string username) : Movable(VIEW_WIDTH / 2, 0, 63, 49), leftPressed(false), rightPressed(false), spacePressed(false), shiftPressed(false), walk_acc(.10f), run_acc(.35f), max_walk(8.f), max_run(12), jump_acc(-4), decelaration(0.7), jumpframe(3), jump_counter(0), move_background(false)
{
    this->username = username;
    this->setVelocity(make_pair(0, 0));
    this->setGravity(make_pair(0, .5f));
}

PlayerModel::~PlayerModel()
{

}

unsigned int PlayerModel::getScore() const
{
    return this->score;
}

void PlayerModel::setScore(unsigned int value)
{
    this->score = value;
}

unsigned short PlayerModel::getLife() const
{
    return this->life;
}

void PlayerModel::setLife(unsigned short value)
{
    this->life = value;
}

void PlayerModel::setUsername(string value)
{
    this->username = value;
}

pair<int, int> PlayerModel::getVelocity() const
{
    return this->velocity;
}

void PlayerModel::setVelocity(pair<int, int> v)
{
    this->velocity = v;
}

void PlayerModel::eventHandler()
{
    const bool onGround = this->pos.second > (VIEW_HEIGHT - this->height - GROUND);

    if(this->leftPressed)
    {
        if(this->shiftPressed)
        {
            if(this->velocity.first > this->max_run * (-1)) //ask
                this->velocity.first -= this->run_acc;
            else {}
        }
        else
        {

            if(this->velocity.first > this->max_walk * (-1))
                this->velocity.first -= this->walk_acc;
            else {
                if(this->velocity.first > this->max_walk * (-1))
                    this->setVelocityX(this->max_walk);
            }
        }
    }

    else if(this->rightPressed)
    {
        if(this->shiftPressed)
        {
            if(this->velocity.first < this->max_run)
                this->velocity.first += this->run_acc;
            else {}
        }
        else
        {
            if(this->velocity.first < this->max_walk)
                this->velocity.first += this->walk_acc;
            else {
                if(this->velocity.first > this->max_walk)
                    this->setVelocityX(this->max_walk);
            }
        }
    }

    else
        this->velocity.first *= decelaration;

    if(this->spacePressed)
    {
        if(onGround)
        {
            this->velocity.second += this->jump_acc * 2;
            this->jump_counter = this->jumpframe;
        }

        else if(this->jump_counter > 0)
        {
            this->velocity.second += this->jump_acc;
            this->jump_counter--;
        }
    }

    else
        this->jump_counter = 0;

}

void PlayerModel::checkCollision()
{
    if(this->pos.second > VIEW_HEIGHT - this->height - GROUND)
    {
        this->velocity.second = 0;
        this->pos.second = VIEW_HEIGHT - this->height - GROUND;
    }

    if(this->pos.first < DEAD_LINE)
    {
        this->velocity.first = 0;
        this->pos.first = DEAD_LINE;
        Utils::log("Player DIED");
    }

    else if(this->pos.first > VIEW_WIDTH - CHUNK_WIDTH - this->width)
    {
        this->pos.first = VIEW_WIDTH - CHUNK_WIDTH - this->width;
        this->move_background = true;
    }
}

void PlayerModel::applyForces()
{
    this->pos += this->velocity;
    this->velocity += this->gravity;
}

std::pair<float, float> PlayerModel::getGravity() const
{
    return this->gravity;
}

void PlayerModel::setGravity(const std::pair<float, float> &value)
{
    this->gravity = value;
}

bool PlayerModel::needMoveBackground() const
{
    return this->move_background;
}

void PlayerModel::setMoveBackground(bool value)
{
    this->move_background = value;
}

void PlayerModel::setVelocityX(float value)
{
    this->velocity.first = value;
}

void PlayerModel::setVelocityY(float value)
{
    this->velocity.second = value;
}

pair<float, float> operator+=(pair<float, float>& a, const pair<float, float>& b)
{
    a.first += b.first;
    a.second += b.second;
    return a;
}

