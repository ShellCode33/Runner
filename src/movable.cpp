#include "movable.h"

using namespace sf;

Movable::Movable()
{

}

Movable::~Movable()
{

}

void Movable::setPosition(Vector2f p)
{
  this->pos.x = p.x;
  this->pos.y = p.y;
}

void Movable::setVelocity(Vector2f v)
{
  this->velocity.x = v.x;
  this->velocity.y = v.y;
}

/*bool inAir(int ground, int height_object) const
{
  return this->pos.y + height_object < ground;
}*/

void Movable::run(Vector2f v, const float move_speed, const float acceleration, const int framerate)
{
  if(Keyboard::isKeyPressed(Keyboard::Right) && v.x < 7)
  {
    v.x += move_speed * acceleration * 1.0f / framerate;
  }
  else if(Keyboard::isKeyPressed(Keyboard::Left) && v.x > -7)
  {
    v.x += -move_speed * acceleration * 1.0f / framerate;
  }
  else
  {
    if(v.x < 0.0001 && v.x > -0,0001)
      v.x = 0;
    else
      v.x /= 1 + move_speed * 1.0f / framerate;
  }
}

void Movable::jump(Vector2f v, const float jump_speed, const float gravity, const int framerate, Vector2f p, const int ground, const int height_object)
{
  if(Keyboard::isKeyPressed(Keyboard::Up) /*&& !inAir*/)
    v.y = -jump_speed;

  /*if(inAir)
  {
    v.y += gravity * 1 / framerate;
    setPosition(p.x, p.y + v.y * 1.0f / framerate);
  }
  else
    setPosition(p.x, ground - height_object);*/
}
