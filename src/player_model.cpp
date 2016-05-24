#include "player_model.h"

using namespace std;

PlayerModel::PlayerModel() : Movable(VIEW_WIDTH / 6, 0, 63, 49), leftPressed(false), rightPressed(false), spacePressed(false), shiftPressed(false), life(100), walk_acc(.10f), run_acc(.35f), max_walk(8.f), max_run(12), jump_acc(-4), max_fall(19), decelaration(0.7), jumpframe(3), jump_counter(0), move_background(false), dead_line(DEAD_LINE_DEFAULT)
{
    this->setVelocity(make_pair(0, 0));
    this->setGravity(make_pair(0, .5f));
}

PlayerModel::~PlayerModel()
{

}

unsigned short PlayerModel::getLife() const
{
    return this->life > 100 ? 0 : this->life; //unsigned short
}

void PlayerModel::setLife(unsigned short value)
{
    this->life = value;
}

pair<int, int> PlayerModel::getVelocity() const
{
    return this->velocity;
}

void PlayerModel::setVelocity(pair<int, int> v)
{
    this->velocity = v;
}

bool PlayerModel::isDead() const
{
    return !this->life || this->life > 100; //life est un unsigned int, donc si life vaut + de 100, c'est que le joueur est mort
}

int PlayerModel::getDeadLine() const
{
    return this->dead_line;
}

void PlayerModel::setDeadLine(int value)
{
    this->dead_line = value;
}

void PlayerModel::addEffect(Effect *effect, unsigned long time_effect)
{
    this->active_effects.push_back(effect);
    this->timer_effects.push_back(Timer(time_effect));
    (*this->timer_effects.rbegin()).begin();
    effect->start(*this);
}

void PlayerModel::processEffects()
{
    int i;
    for(i = 0; i < (int)this->timer_effects.size(); i++)
        if(this->timer_effects.at(i).isFinish())
        {
            cout << "Delete effect" << endl;
            vector<Effect*>::iterator it = this->active_effects.begin();
            vector<Timer>::iterator it2 = this->timer_effects.begin();

            int j;
            for(j = 0; j < i; j++, ++it, ++it2); //On se déplace dans le vecteur

            (*it)->stop(*this);

            Utils::log("test2:");
            this->active_effects.erase(it);
            this->timer_effects.erase(it2);
            Utils::log("removed?");
        }
}

void PlayerModel::eventHandler()
{
    const bool onGround = this->pos.second > (VIEW_HEIGHT - this->height - GROUND_DEFAULT);

    if(this->leftPressed)
    {
        if(this->velocity.first > 0)
            this->setVelocityX(0.);

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
        if(this->velocity.first < 0)
            this->setVelocityX(0.);

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
    if(this->pos.second > VIEW_HEIGHT - this->height - GROUND_DEFAULT)
    {
        this->velocity.second = 0;
        this->pos.second = VIEW_HEIGHT - this->height - GROUND_DEFAULT;
    }

    if(this->pos.first < DEAD_LINE_DEFAULT + this->dead_line)
    {
        this->velocity.first = 0;
        Utils::log("Player died");
        this->life = 0;
    }

    else if(this->pos.first > VIEW_WIDTH - CHUNK_WIDTH - CHUNK_WIDTH / 2 - this->width)
    {
        this->pos.first = VIEW_WIDTH - CHUNK_WIDTH - CHUNK_WIDTH / 2 - this->width;
        this->move_background = true;
    }
}

void PlayerModel::applyForces()
{
    this->pos += this->velocity;

    if(this->velocity.second < this->max_fall)
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

