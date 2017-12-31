#include "about_tab.h"
#include "window.h"

using namespace sf;
using namespace std;

AboutTab::AboutTab() : first_snoop(20.0), second_snoop(20.0)
{
    srand(time(NULL));

    assert(this->illu_texture.loadFromFile(ILLUMINATI_IMG));
    this->illuminati.setTexture(illu_texture);
    this->illuminati.setPosition((VIEW_WIDTH-this->illu_texture.getSize().x) / 2, 10);


    this->snoop_texture = new Texture();
    this->snoop_texture->loadFromFile(SNOOP_DOGG_IMG);
    this->first_snoop.setTexture(*this->snoop_texture);

    this->snoop_texture_reverse = new Texture();
    this->snoop_texture_reverse->loadFromFile(SNOOP_DOGG_REVERSE_IMG);

    int j, i;
    for(j = 0; j < 5; j++)
    {
        for(i = 0; i < 11; i++)
            this->first_snoop.addClip(IntRect(290*i, 595*j, 280, 595));
    }

    for(i = 0; i < 3; i++)
        this->first_snoop.addClip(IntRect(290*i, j*595, 280, 595));


    this->first_snoop.setPosition(200, VIEW_HEIGHT-595); //595 = taille du snoop

    for(j = 0; j < 5; j++)
    {
        for(i = 10; i >= 0; i--)
            this->second_snoop.addClip(IntRect(290*i, 595*j, 280, 595));
    }

    for(i = 10; i >= 8; i--)
        this->second_snoop.addClip(IntRect(290*i, j*595, 280, 595));

    this->second_snoop.setTexture(*this->snoop_texture_reverse);
    this->second_snoop.setPosition(VIEW_WIDTH-200-280, VIEW_HEIGHT-595);


    assert(font.loadFromFile(ONTHEMOVE_TTF));

    //Pas très propre mais necessaire car la SFML n'est pas capable de centrer horizontalement du texte multi-ligne
    this->text[0].setString(Utils::translate(WindowRunner::getSetting("lang"), "about.dev"));
    this->text[1].setString(String(L"J3ry"));
    this->text[2].setString(String("&"));
    this->text[3].setString(String(L"ShellCode"));


    for(i = 0; i < (int)(sizeof(this->text)/sizeof(Text)); i++)
    {
        this->text[i].setFont(font);
        this->text[i].setCharacterSize(100);
        this->text[i].setColor(Color::Black);
        this->text[i].setPosition((VIEW_WIDTH-text[i].getLocalBounds().width) / 2, (VIEW_HEIGHT-text[i].getLocalBounds().height) / 1.7 + i*100);
    }
}

AboutTab::~AboutTab()
{
    delete this->snoop_texture;
    delete this->snoop_texture_reverse;
}

void AboutTab::draw(RenderTarget &target, RenderStates states) const
{
    target.clear(Color(rand() % 256, rand() % 256, rand() % 256));
    target.draw(this->first_snoop, states);
    target.draw(this->second_snoop, states);

    int i;
    for(i = 0; i < (int)(sizeof(text)/sizeof(Text)); i++)
        target.draw(this->text[i]);

    target.draw(this->illuminati, states);
}

void AboutTab::update()
{
    this->first_snoop.update();
    this->second_snoop.update();
    this->text[0].setString(Utils::translate(WindowRunner::getSetting("lang"), "about.dev"));
}

void AboutTab::processEvent(WindowRunner & window, Event & event)
{
    if((event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) || (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left))
        window.setState(MENU);
}
