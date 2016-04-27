#include "piece_view.h"

using namespace std;
using namespace sf;

PieceView::PieceView(PieceModel &model) : Animation(100.0), model(model)
{
    assert(this->piece_texture.loadFromFile("PIECE_IMG"));
    this->setTexture(this->piece_texture);

    this->model.setWidth(30);
    this->model.setHeight(35);

    for(unsigned int i = 0; i < 8; i++)
        this->addClip(IntRect(model.getWidth() * i, 0, model.getWidth(), model.getHeight()));
    this->setAnimEnabled(true);
}

PieceView::~PieceView()
{

}

void PieceView::update()
{

}
