/*!
 * \file option_tab.h
 * \class OptionTab
 * \brief classe pour la gestion de l'écran d'option
 * \author Jérémie
 *
 */

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
    void processEvent(sf::RenderWindow &window, sf::Event &event, State &state);
    void update();

private:
    std::vector<std::string> available_langages;
    std::vector<sf::Texture*> flags_texture;
    std::vector<sf::Sprite*> flags_sprites;
    sf::RectangleShape board;

    sf::Font font;
    sf::Text chooseLang;
    sf::Text chooseVolume;

    int volume;
    sf::Text volume_text;

    sf::Text chooseDifficulty;
    int difficulty;
    sf::Text difficulties_text[3]; //3difficultés


};

#endif //OPTION_TAB_H
