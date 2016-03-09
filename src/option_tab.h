#ifndef OPTION_TAB_H
#define OPTION_TAB_H

#include <SFML/Graphics.hpp>

class OptionTab : public sf::Drawable
{
public:
    OptionTab();
    ~OptionTab();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};

#endif //OPTION_TAB_H
