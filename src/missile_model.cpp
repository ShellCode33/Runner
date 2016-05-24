#include "missile_model.h"

using namespace std;

MissileModel::MissileModel(PlayerModel &player) : Movable(CHUNK_WIDTH / 2, 75, 74, 24), player(player), angle(0), moving(false), exploded(false), update_timer(10.)
{
    this->update_timer.begin();
}

MissileModel::~MissileModel()
{

}

void MissileModel::update()
{
    if(!this->exploded)
    {
        pair<float, float> player_pos = this->player.getPosition();
        pair<float, float> direction(player_pos.first + this->player.getWidth() / 2 - this->getX(), player_pos.second + this->player.getHeight() / 2 - this->getY());

        int new_angle = atan2(direction.second, direction.first) * 180 / 3.14159;

        if(new_angle < 0)
            new_angle += 360;

        //cout << "angle: " << new_angle << endl;

        if(!this->moving)
            this->angle = new_angle;

        else if(this->update_timer.isFinish())
        {
            this->update_timer.reset();

            if(new_angle > angle || abs(new_angle - angle) > 180)
                this->angle += 1;

            else
                this->angle -= 1;

            if(this->angle < 0)
                this->angle += 360;

            else if(this->angle >= 360)
                this->angle -= 360;

            int x_speed, y_speed; //Le déplacement selon x et y doit se faire en fonction de l'angle actuel (this->angle)

            /* On sépare en 4 cas différents :
             * - Lorsque le joueur est en haut à gauche du missile
             * - Lorsque le joueur est en bas à gauche du missile
             * - Lorsque le joueur est en bas à droite du missile
             * - Lorsque le joueur est en haut à droite du missile
             */

            if(this->angle > 270 && this->angle <= 360)
            {
                //cout << "angle en haut à droite : " << this->angle << endl;
                x_speed = (this->angle - 270) * MISSILE_SPEED / 90;
                y_speed = x_speed - MISSILE_SPEED;

                //cout << "x_speed: " << x_speed << " y_speed: " << y_speed << endl;
            }

            else if(this->angle > 180 && this->angle <= 270)
            {
                //cout << "angle en haut à gauche : " << this->angle << endl;
                y_speed = -(this->angle - 180) * MISSILE_SPEED / 90;
                x_speed = -(y_speed + MISSILE_SPEED);

                //cout << "x_speed: " << x_speed << " y_speed: " << y_speed << endl;
            }

            else if(this->angle > 90 && this->angle <= 180)
            {
                //cout << "angle en bas à gauche : " << this->angle << endl;
                x_speed = -(this->angle - 90) * MISSILE_SPEED / 90;
                y_speed = (MISSILE_SPEED + x_speed);

                //cout << "x_speed: " << x_speed << " y_speed: " << y_speed << endl;
            }

            else
            {
                //cout << "angle en bas à droite : " << this->angle << endl;
                y_speed = this->angle * MISSILE_SPEED / 90;
                x_speed = MISSILE_SPEED - y_speed;

                //cout << "x_speed: " << x_speed << " y_speed: " << y_speed << endl;
            }

            assert(abs(x_speed) + abs(y_speed) <= MISSILE_SPEED);

            this->setPosition(make_pair(this->getX() + x_speed, this->getY() + y_speed));

            //Collisions environnement du missile
            if(this->getX() < 0 || this->getY() <  0 || this->getY() > VIEW_HEIGHT - GROUND_DEFAULT)
            {
                this->exploded = true;
                return;
            }
        }

        if(!moving && abs(direction.first) < MISSILE_DETECTION)
            moving = true;
    }
}

void MissileModel::action(Player &player)
{
    this->exploded = true;
    player.getModel()->setLife(player.getModel()->getLife() - 40);
}

bool MissileModel::checkCollision(Movable &m) const
{
    if(this->exploded)
        return false;

    AABB playerRect, missileRect;

    playerRect.x = m.getX();
    playerRect.y = m.getY();
    playerRect.w = m.getWidth();
    playerRect.h = m.getHeight();

    missileRect.x = this->getX();
    missileRect.y = this->getY();
    missileRect.w = this->getWidth();
    missileRect.h = this->getHeight();

    return Collision::AABBintersectAABB(playerRect, missileRect);
}

float MissileModel::getAngle() const
{
    return this->angle;
}
bool MissileModel::getExploded() const
{
    return this->exploded;
}
