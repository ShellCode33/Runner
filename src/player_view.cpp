#include "player_view.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(string filename_player_img)
{
    this->player_texture.loadFromFile(filename_player_img);
    this->setTexture(this->player_texture);
    this->setPosition(500, 500);
    this->addClip(IntRect(0, 0, 222, 300));
    this->addClip(IntRect(222, 0, 222, 300));
    this->addClip(IntRect(444, 0, 222, 300));
}

PlayerView::~PlayerView()
{

}
