#ifndef ABOUT_TAB_H
#define ABOUT_TAB_H

#include <SFML/Graphics.hpp>
#include <ctime>
#include "animation.h"
#include "const.h"

class WindowRunner;

class AboutTab : public sf::Drawable
{
public:
    AboutTab();
    ~AboutTab();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void update();
    void processEvent(WindowRunner & window, sf::Event & event);


private:
    sf::Texture *snoop_texture, *snoop_texture_reverse; //grosse image, on va l'allouer sur le heap ;)
    Animation first_snoop, second_snoop;

    sf::Texture illu_texture;
    sf::Sprite illuminati;

    sf::Font font;
    sf::Text text[4]; //Obligé d'en faire un tableau car la SFML ne gère pas le text-align center

};

#endif // ABOUT_TAB_H
