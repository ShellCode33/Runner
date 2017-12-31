/*!
 * \file option_tab.h
 * \class OptionTab
 * \brief classe pour la gestion de l'écran d'option
 * \author J3ry
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
    std::vector<std::string> available_langages; /*!< Contient les différentes langues supportées */
    std::vector<sf::Texture*> flags_texture; /*!< Textures des differents drapeaux pour le support multi-langues */
    std::vector<sf::Sprite*> flags_sprites; /*!< Sprites des differents drapeaux pour le support multi-langues */
    sf::RectangleShape board; /*!< Background */

    sf::Font font;
    sf::Text chooseLang;
    sf::Text chooseVolume;

    int volume; /*!< Volume du jeu de 0 à 100 (pas encore implémenté) */
    sf::Text volume_text;

    sf::Text chooseDifficulty;
    int difficulty; /*!< difficulté 1, 2, 3 */
    sf::Text difficulties_text[3]; /*!< 3difficultés */


};

#endif //OPTION_TAB_H
