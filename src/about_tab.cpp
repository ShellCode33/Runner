#include "about_tab.h"
#include "window.h"

using namespace sf;

AboutTab::AboutTab(WindowRunner &window)
{
    srand(time(NULL));

    this->snoop_texture = new Texture();
    this->snoop_texture->loadFromFile(SNOOP_DOGG_ANIM);
    this->first_snoop.setTexture(*this->snoop_texture);

    int i;
    for(i = 0; i < 29; i++)
        this->first_snoop.addClip(IntRect(290*i, 0, 280, 595));

    for(i = 0; i < 29; i++) // Au total, il y a 58 (=29+29) images snoop qui composent son animation
        this->first_snoop.addClip(IntRect(290*i, 595, 280, 595));

    this->first_snoop.setPosition(200, VIEW_HEIGHT-595); //595 = taille du snoop
    this->second_snoop = this->first_snoop;
    this->second_snoop.setPosition(VIEW_WIDTH-200-280, VIEW_HEIGHT-595);
}

AboutTab::~AboutTab()
{
    delete this->snoop_texture;
}

void AboutTab::draw(RenderTarget &target, RenderStates states) const
{
    //target.clear(Color(rand() % 256, rand() % 256, rand() % 256));
    target.draw(this->first_snoop);
    target.draw(this->second_snoop);
}

void AboutTab::update()
{
    this->first_snoop.update();
    this->second_snoop.update();
}
