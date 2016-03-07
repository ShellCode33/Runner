#include "player_view.h"

using namespace std;
using namespace sf;

PlayerView::PlayerView(string filename_player_img)
{
    this->player_texture.loadFromFile(filename_player_img);
    this->sprite.setTexture(this->player_texture);
    this->sprite.setPosition(500, 500);
    this->addClip(IntRect(0, 0, 222, 300));
    this->addClip(IntRect(222, 0, 222, 300));
    this->addClip(IntRect(444, 0, 222, 300));
}

PlayerView::~PlayerView()
{

}

void PlayerView::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(this->sprite);
}
