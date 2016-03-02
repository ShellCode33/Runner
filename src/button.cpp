#include "button.h"

using namespace std;
using namespace sf;

Button::Button(string img_filename, int pos_x, int pos_y, int width, int height) : pos_x(pos_x), pos_y(pos_y), width(width), height(height)
{
    Texture texture;
    texture.loadFromFile(img_filename);
    sprite = new Sprite(texture);
}

Button::~Button()
{
    delete sprite;
}

void Button::setBoundaries(int pos_x_img, int pos_y_img, int width_img, int height_img )
{

}
