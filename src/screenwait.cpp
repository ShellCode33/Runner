#include "screenwait.h"
#include "window.h"

using namespace std;
using namespace sf;

ScreenWait::ScreenWait(WindowRunner* window, const string filename, const string text)
{
    this->window = window;
    this->background_texture = NULL;

    this->background = new Sprite();
    setBackground(filename);

    this->font = new Font();
    assert(this->font->loadFromFile("../Runner/fonts/onthemove.ttf")); //ttf par défaut

    this->text = new Text();
    setText(text);
    this->text->setFont(*this->font);
    this->text->setCharacterSize(100);
    this->text->setColor(Color::Black);
}

ScreenWait::~ScreenWait()
{
    delete this->background;
    delete this->background_texture;
    delete this->font;

    if(this->text != NULL)
        delete this->text;
}

void ScreenWait::setBackground(const string filename)
{
    this->background_texture = new Texture();
    assert(this->background_texture->loadFromFile(filename));
    this->background->setTexture(*this->background_texture);
}

Sprite& ScreenWait::getBackground() const
{
    return *this->background;
}

Text& ScreenWait::getText() const
{
    return *this->text;
}

void ScreenWait::setText(string value)
{
    this->text->setString(value);
}

void ScreenWait::setTextPosition(const Vector2f pos)
{
    this->text->setPosition(pos);
}

float ScreenWait::getTextWidth() const
{
    return this->text->getLocalBounds().width;
}

float ScreenWait::getTextHeight() const
{
    return this->text->getLocalBounds().height;
}
