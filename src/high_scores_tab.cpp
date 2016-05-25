#include "high_scores_tab.h"
#include "window.h"

using namespace sf;
using namespace std;

HighScoresTab::HighScoresTab() : ScreenWait(HIGHSCORES_BACKGROUND_IMG, "")
{
    assert(this->font.loadFromFile(ONTHEMOVE_TTF));
    this->board.setSize(Vector2f(VIEW_WIDTH / 3, VIEW_HEIGHT - VIEW_HEIGHT / 3));
    this->board.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2);
    this->board.setFillColor(Color(150, 25, 25, 255));

    int i;
    for(i = 1; i < MAX_BEST_SCORES+1; i++)
    {
        this->scores_text[i].setCharacterSize(40);
        this->scores_text[i].setFont(this->font);
        this->scores_text[i].setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 50, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 20 + i*60);
    }

    this->scores_text[0].setFont(this->font);
    this->scores_text[0].setCharacterSize(60);
    this->scores_text[0].setStyle(Text::Bold);
    this->scores_text[0].setString("Rank        Score - Pseudo");
    this->scores_text[0].setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 50, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 5);
}

HighScoresTab::~HighScoresTab()
{

}

void HighScoresTab::processEvent(sf::Event &event, State &state)
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    {
        state = MENU;
    }
}

void HighScoresTab::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    ScreenWait::draw(target, states);
    target.draw(this->board);

    int i;
    for(i = 0; i < MAX_BEST_SCORES+1; i++)
        target.draw(this->scores_text[i]);
}

void HighScoresTab::update()
{
    cout << "update high scores" << endl;
    this->scores = Utils::getScores();

    unsigned int i;
    for(i = 0; i < this->scores.size(); i++)
    {
        this->scores_text[i+1].setString(to_string(i+1) + "                   " + to_string(this->scores[i].first) + " - " + this->scores[i].second);
    }

    cout << "update complete" << endl;
}
