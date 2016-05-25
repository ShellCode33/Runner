#include "button.h"
#include "window.h"

using namespace std;
using namespace sf;

Button::Button(const string & text, const State action, const int pos_x, const int pos_y, const int width, const int height) : action(action), pos_x(pos_x), pos_y(pos_y), width(width), height(height)
{
    this->audio.load(CLICK_BUTTON_SNG);
    this->audio.setPlayingOffset(sf::milliseconds(320));

    assert(this->font.loadFromFile(PIXEL_TTF));
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setColor(Color::Black);
    this->text.setCharacterSize(40);

    assert(this->texture.loadFromFile(BUTTON_IMG));
    this->texture_hover = texture; //par défaut la texture hover est la meme que la texture de base du bouton

    this->sprite = new Sprite(texture);
    this->sprite->setPosition(this->pos_x, this->pos_y);


    this->text.setOrigin(this->text.getLocalBounds().width / 2.1, this->text.getLocalBounds().height); // divisé par 2.1 car la taille du Text est plus grande que la taille de la police
    this->text.setPosition(this->pos_x + this->width / 2, this->pos_y + this->height / 2);
    setBoundaries(0, 0, this->width, this->height); //default
}

Button::~Button()
{
    delete this->sprite;
}

void Button::setImage(const string filename)
{
    assert(this->texture.loadFromFile(filename));
    this->sprite->setTexture(this->texture);
}

void Button::setBoundaries(const int pos_x, const int pos_y, const int width, const int height)
{
    this->sprite->setTextureRect(IntRect(pos_x, pos_y, width, height));
}

void Button::draw(RenderTarget& target, RenderStates states) const
{
    target.draw(*this->sprite, states);
    target.draw(this->text, states);
}

void Button::processEvent(WindowRunner &window, Event &event)
{
    RenderWindow & render = window.getRender();
    Vector2i window_mouse_pos = Mouse::getPosition(render);
    Vector2f mouse_pos = render.mapPixelToCoords(window_mouse_pos);

    if(event.type == Event::MouseMoved)
    {
        if((mouse_pos.y > this->pos_y && mouse_pos.y < this->pos_y + this->height) && (mouse_pos.x > this->pos_x && mouse_pos.x < this->pos_x + this->width) )
            setBoundaries(this->width, 0, this->width, this->height);

        else
            setBoundaries(0, 0, this->width, this->height);
    }

    if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        if((mouse_pos.y > this->pos_y && mouse_pos.y < this->pos_y + this->height) && (mouse_pos.x > this->pos_x && mouse_pos.x < this->pos_x + this->width) )
        {
            this->audio.play();
            window.setState(this->action);
        }
    }
}

void Button::setPosition(int x, int y)
{
    this->pos_x = x;
    this->pos_y = y;
    this->sprite->setPosition(this->pos_x, this->pos_y);
    this->text.setPosition(this->pos_x + this->width / 2, this->pos_y + this->height / 2);
}

std::pair<int, int> Button::getPosition() const
{
    return make_pair(this->pos_x, this->pos_y);
}

std::pair<int, int> Button::getSize() const
{
    return make_pair(this->width, this->height);
}

void Button::setText(string text)
{
    this->text.setString(toUpper(text));
    this->text.setOrigin(this->text.getLocalBounds().width / 2.1, this->text.getLocalBounds().height); // divisé par 2.1 car la taille du Text est plus grande que la taille de la police
    this->text.setPosition(this->pos_x + this->width / 2, this->pos_y + this->height / 2);
}

string Button::toUpper(string str) const
{
    string tmp = "";

    for(char c : str)
        tmp += toupper(c);

    return tmp;
}
