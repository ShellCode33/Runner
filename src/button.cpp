#include "button.h"

using namespace std;
using namespace sf;

Button::Button(const string & text, const int pos_x, const int pos_y, const int width, const int height) : pos_x(pos_x), pos_y(pos_y), width(width), height(height)
{
    this->font = new Font();
    this->text = new Text();
    this->font->loadFromFile(ONTHEMOVE_TTF);
    this->text->setFont(*this->font);
    this->text->setString(text);

    this->texture = new Texture();
    this->texture->loadFromFile(BUTTON_MENU_IMG);
    this->sprite = new Sprite(*texture);

    setBoundaries(0, 0, width, height); //default
}

Button::~Button()
{
    delete this->font;
    delete this->text;
    delete this->texture;
    delete this->sprite;
}

void Button::setImage(const string filename)
{
    this->texture->loadFromFile(filename);
    this->sprite->setTexture(*this->texture);
}

void Button::setBoundaries(const int pos_x, const int pos_y, const int width, const int height)
{
    this->sprite->setTextureRect(IntRect(pos_x, pos_y, width, height));
}

<<<<<<< HEAD
void Button::setBoundaries(int pos_x_img, int pos_y_img, int width_img, int height_img )
=======
void Button::draw(RenderTarget& target, RenderStates states) const
>>>>>>> e4de024d6560b78ead09ca840cff7ed8e55dd141
{
    this->sprite->setPosition(this->pos_x, this->pos_y);
    this->text->setPosition(this->sprite->getPosition().x + (this->sprite->getLocalBounds().width - this->text->getLocalBounds().width) / 2, this->sprite->getPosition().y + (this->sprite->getLocalBounds().height - this->text->getLocalBounds().height) / 3);

    target.draw(*this->sprite, states);
    target.draw(*this->text, states);
}
