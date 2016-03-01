#include "button.h"

using namespace std;
using namespace sf;

Button::Button(string filename, int pos_x, int pos_y, int width, int height) : pos_x(pos_x), pos_y(pos_y), width(width), height(height)
{
  Texture texture;
  texture.loadFromFile(filename);
  sprite = new Sprite(texture);
}

Button::~Button()
{
  delete sprite;
}
