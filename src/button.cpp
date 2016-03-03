#include "button.h"
#include "window.h"

using namespace std;
using namespace sf;

Button::Button(const string & text, const int pos_x, const int pos_y, const int width, const int height) : pos_x(pos_x), pos_y(pos_y), width(width), height(height)
{
    this->font = new Font();
    this->text = new Text();
    this->font->loadFromFile(ONTHEMOVE_TTF);
    this->text->setFont(*this->font);
    this->text->setString(text);
    this->text->setColor(Color::Black);

    this->texture = new Texture();
    this->texture_hover = texture; //par défaut la texture hover est la meme que la texture de base du bouton
    this->texture->loadFromFile(BUTTON_MENU_IMG);
    this->sprite = new Sprite(*texture);

    setBoundaries(0, 50, width, height); //default
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

void Button::draw(RenderTarget& target, RenderStates states) const
{
    this->sprite->setPosition(this->pos_x, this->pos_y);
    this->text->setPosition(this->sprite->getPosition().x + (this->sprite->getLocalBounds().width - this->text->getLocalBounds().width) / 2, this->sprite->getPosition().y + (this->sprite->getLocalBounds().height - this->text->getLocalBounds().height) / 3);

    target.draw(*this->sprite, states);
    target.draw(*this->text, states);
}

void Button::processEvent(WindowRunner &window, Event &event)
{
    if(event.type == Event::MouseMoved && window.getState() == MENU)
    {
        float x_mouse = event.mouseMove.x*1.38;
        float y_mouse = event.mouseMove.y*1.386; //Je ne comprend pas pourquoi les position sont mauvaises

        //cout << x_mouse << " " << y_mouse << endl;

        if((y_mouse > this->pos_y && y_mouse < this->pos_y + this->height) && (x_mouse > this->pos_x && x_mouse < this->pos_x + this->width) )
            setBoundaries(0, 0, this->width, this->height);

        else
            setBoundaries(0, 50, this->width, this->height);
    }
}
