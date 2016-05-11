#ifndef OPTION_TAB_H
#define OPTION_TAB_H

#include <SFML/Graphics.hpp>
#include "screenwait.h"

class OptionTab : public ScreenWait
{
public:
    OptionTab();
    ~OptionTab();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void processEvent(sf::Event &event, State &state);

private:

};

#endif //OPTION_TAB_H
