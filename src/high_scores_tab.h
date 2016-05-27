/*!
 * \file high_score_tab.h
 * \class HighScoreTab
 * \brief classe s'occupant de l'écran de meilleurs scores
 * \author Clément
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
    sf::RectangleShape board;
    std::vector<std::pair<unsigned long, std::string> > scores;
    sf::Font font;
    sf::Text scores_text[MAX_BEST_SCORES+1];

};

#endif // HIGH_SCORES_H
