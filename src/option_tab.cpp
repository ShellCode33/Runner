#include "option_tab.h"
#include "window.h"

using namespace std;
using namespace sf;

OptionTab::OptionTab() : ScreenWait(OPTIONS_BG, ""), settingsChanged(false)
{
    assert(this->font.loadFromFile(ONTHEMOVE_TTF));
    this->board.setSize(Vector2f(VIEW_WIDTH / 3, VIEW_HEIGHT - VIEW_HEIGHT / 3));
    this->board.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2);
    this->board.setFillColor(Color(3, 22, 0, 255));

    this->available_langages = Utils::getAvailableLanguages();

    this->chooseLang.setFont(this->font);
    this->chooseLang.setCharacterSize(50);
    this->chooseLang.setString(Utils::translate(WindowRunner::getSetting("lang"), "lang.option"));
    this->chooseLang.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 30, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 30);

    int i;
    for(i = 0; i < (int)this->available_langages.size(); i++)
    {
        Texture *texture = new Texture();
        Sprite *sprite = new Sprite();

        if(texture->loadFromFile("img/" + this->available_langages.at(i) + ".png"))
        {
            this->flags_texture.push_back(texture);
            sprite->setTexture(*texture);
            sprite->setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 30 *(i+1) + 50 * i, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 100);
            this->flags_sprites.push_back(sprite);
        }
    }

    this->chooseVolume.setFont(this->font);
    this->chooseVolume.setCharacterSize(50);
    this->chooseVolume.setString(Utils::translate(WindowRunner::getSetting("lang"), "volume.option"));
    this->chooseVolume.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 30, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 150);

    this->volume = atoi(WindowRunner::getSetting("volume").c_str());
    this->volume_text.setFont(this->font);
    this->volume_text.setCharacterSize(50);
    this->volume_text.setString(to_string(volume));
    this->volume_text.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 200, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 200);



    this->chooseDifficulty.setFont(this->font);
    this->chooseDifficulty.setCharacterSize(50);
    this->chooseDifficulty.setString(Utils::translate(WindowRunner::getSetting("lang"), "difficulty.option"));
    this->chooseDifficulty.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 30, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 290);

    this->difficulty = atoi(WindowRunner::getSetting("difficulty").c_str());

    for(i = 0; i < 3; i++)
    {
        this->difficulties_text[i].setFont(this->font);
        this->difficulties_text[i].setCharacterSize(50);
        this->difficulties_text[i].setString(Utils::translate(WindowRunner::getSetting("lang"), "difficulty." + to_string(i+1)));
        this->difficulties_text[i].setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 30 + 230*i, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 340);
    }
}

OptionTab::~OptionTab()
{
    for(Sprite *s : this->flags_sprites)
        delete s;
}

void OptionTab::draw(RenderTarget &target, RenderStates states) const
{
    ScreenWait::draw(target, states);
    target.draw(this->board);
    target.draw(this->chooseLang);

    for(Sprite * s : this->flags_sprites)
        target.draw(*s);

    target.draw(this->chooseVolume);

    int i;
    for(i = 0; i < volume / 10; i++)
    {
        RectangleShape rect(Vector2f(3, (i+1)*3));
        rect.setOrigin(Vector2f(0, (i+1)*3));
        rect.setFillColor(Color(255, 255, 255, 255));
        rect.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 40 + i*15, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 250);
        target.draw(rect, states);
    }

    for(; i < 10; i++)
    {
        RectangleShape rect(Vector2f(3, (i+1)*3));
        rect.setOrigin(Vector2f(0, (i+1)*3));
        rect.setFillColor(Color(0, 0, 0, 255));
        rect.setPosition((VIEW_WIDTH - VIEW_WIDTH / 3) / 2 + 40 + i*15, (VIEW_HEIGHT - (VIEW_HEIGHT - VIEW_HEIGHT / 3)) / 2 + 250);
        target.draw(rect, states);
    }

    target.draw(this->volume_text);

    target.draw(this->chooseDifficulty);

    for(i = 0; i < 3; i++)
    {
        Text text = this->difficulties_text[i]; //copy to modify color in const draw method

        if(difficulty == (i+1))
            text.setColor(Color(255, 255, 255, 255));

        else
            text.setColor(Color(153, 153, 102, 255));

        target.draw(text);
    }
}

void OptionTab::processEvent(RenderWindow &window, Event &event, State &state)
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    {
        //SAVE SETTINGS
        state = MENU;
    }

    else if(event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
    {
        Vector2f mouse_pos = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));

        //APPUI DRAPEAUX
        int lang;
        int i = 0;

        for(i = 0; i < (int)this->available_langages.size(); i++)
        {
            if(mouse_pos.x > this->flags_sprites.at(i)->getPosition().x && mouse_pos.x < this->flags_sprites.at(i)->getPosition().x + this->flags_sprites.at(i)->getLocalBounds().width && mouse_pos.y > this->flags_sprites.at(i)->getPosition().y && mouse_pos.y < this->flags_sprites.at(i)->getPosition().y + this->flags_sprites.at(i)->getLocalBounds().height)
            {
                lang = i;
                break;
            }

            else
                lang = -1;
        }

        if(lang != -1)
        {
            this->settingsChanged = true;
            WindowRunner::writeSetting("lang", this->available_langages.at(lang));
        }

        else
            Utils::log("Language not found");
    }
}
