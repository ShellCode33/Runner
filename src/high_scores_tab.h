/*!
 * \file high_score_tab.h
 * \class HighScoreTab
 * \brief classe s'occupant de l'écran de meilleurs scores
 * \author ShellCode
 */

#ifndef HIGH_SCORES_H
#define HIGH_SCORES_H

#include <SFML/Graphics.hpp>
#include "screenwait.h"
#include "utils.h"

class HighScoresTab : public ScreenWait
{
public:
    HighScoresTab();
    virtual ~HighScoresTab();
    virtual void processEvent(sf::Event &event, State &state);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void update();

private:
    sf::RectangleShape board; /*!< Background */
    std::vector<std::pair<unsigned long, std::string> > scores; /*!< Vecteur de pair entre score et pseudo pour faire les correspondances */
    sf::Font font;
    sf::Text scores_text[MAX_BEST_SCORES+1]; /*!< Tableau qui contiendra l'ensemble des meilleurs scores qui seront ensuite affichés  */

};

#endif // HIGH_SCORES_H
