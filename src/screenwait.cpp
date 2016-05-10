#include "screenwait.h"
#include "window.h"

using namespace std;
using namespace sf;

ScreenWait::ScreenWait(WindowRunner* window, const string filename, const string text)
{
    this->window = window;
    this->background_texture = new Texture();

    this->background = new Sprite();
    this->setBackground(filename);

    this->font = new Font();
    assert(this->font->loadFromFile(ONTHEMOVE_TTF)); //ttf par défaut
    this->text = new Text();
    this->setText(text);
    this->text->setFont(*this->font);
    this->text->setCharacterSize(100);
    this->text->setColor(Color::Black);
}

ScreenWait::~ScreenWait()
{
    delete this->background_texture;
    delete this->background;
    delete this->text;
    delete this->font;
}

void ScreenWait::setBackground(const string filename)
{
    assert(this->background_texture->loadFromFile(filename));
    this->background->setTexture(*this->background_texture);
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

void ScreenWait::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(*this->background, states);
    target.draw(*this->text, states);
}

void ScreenWait::processEvent(Event & event, State & state)
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
        this->window->setState(MENU);

}
