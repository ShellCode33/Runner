#include "game_view.h"
#include "window.h"

using namespace std;
using namespace sf;

GameView::GameView(WindowRunner &window, GameModel &model, Player &player, list<Chunk *> &chunks) : window(window), game_model(model), fire(20.0), fire2(20.0), lava(20.0), player(player), chunks(chunks)
{
    assert(this->fire_texture.loadFromFile(FIRE_ANIM));
    this->fire.setTexture(this->fire_texture);

    int i, j;
    for(i = 0; i < 12; i++)
        for(j = 0; j < 4; j++)
            this->fire.addClip(IntRect(j*600, i*FIRE_DEFAULT_POS, 600, FIRE_DEFAULT_POS));

    this->fire.setPosition(FIRE_DEFAULT_POS, 0);
    this->fire.setRotation(90);
    this->fire2 = this->fire;
    this->fire2.scale(-1.f, 1.f);
    this->fire2.setPosition(FIRE_DEFAULT_POS, this->fire.getLocalBounds().width*2);
    this->fire2.setRotation(90);

    assert(this->score_font.loadFromFile(ONTHEMOVE_TTF));
    this->score_display.setFont(this->score_font);
    this->score_display.setCharacterSize(50);
    this->score_display.setString("Score: 0");
    this->score_display.setPosition(VIEW_WIDTH - this->score_display.getLocalBounds().width - 20, VIEW_HEIGHT - 100); //-20 pour l'espace depuis l'écran


    assert(this->lava_texture.loadFromFile(LAVA_IMG));
    this->lava.setTexture(this->lava_texture);

    for(i = 0; i < 7; i++)
        this->lava.addClip(IntRect(130*i, 112, 128, 128));

    for(i = 0; i < 4; i++)
        this->lava.addClip(IntRect(130*i, 114+128, 128, 128));

    this->lava.setOffset(2, 2);
}

GameView::~GameView()
{

}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    for(Chunk *c : this->chunks)
            c->draw(target, states);

    if(!this->player.getModel()->isDead())
        target.draw(*this->player.getView(), states);

    else
        target.draw(*this->player.getView()->getDeadAnim(), states);

    target.draw(this->fire, states);
    target.draw(this->fire2, states);
    target.draw(this->score_display, states);

    for(const Sprite& s : this->lava_sprites)
        target.draw(s, states);
}

void GameView::processEvent(Event &event)
{
    if(this->window.getState() == SURVIVAL || this->window.getState() == CAMPAIGN)
    {
        if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
            this->window.setState(MENU);

        this->player.getView()->processEvents(this->window, event);
    }
}

void GameView::update()
{
    this->player.getView()->update(); //On met à jouer l'affichage du joueur
    this->fire.update(); //On met l'animation du feu à jour
    this->fire2.update();

    this->fire.setPosition(FIRE_DEFAULT_POS + this->game_model.getFireOffset(), this->fire.getPosition().y);
    this->fire2.setPosition(FIRE_DEFAULT_POS + this->game_model.getFireOffset(), this->fire2.getPosition().y);

    //On met à jour l'affichage du score
    this->score_display.setString("Score: " + to_string(this->game_model.getScore()));
    this->score_display.setPosition(VIEW_WIDTH - this->score_display.getLocalBounds().width - 20, VIEW_HEIGHT - 100);


    //Lave
    this->lava.update();
    this->lava_sprites.clear();
    int lava_w = this->lava.getLocalBounds().width;
    int lava_h = this->lava.getLocalBounds().height;
    int nb_lava_x = (DEAD_LINE_DEFAULT + this->game_model.getFireOffset()) / lava_w + 1; //+1 car il c'est une division entière et il y aura des demi-blocs de lave
    int nb_lava_y = VIEW_HEIGHT / lava_h + 1;

    int i, j;
    for(i = 0; i < nb_lava_x; i++)
    {
        for(j = 0; j < nb_lava_y; j++)
        {
            this->lava.setRotation(90);
            this->lava.setPosition(this->game_model.getFireOffset()-i*lava_w, j*lava_h);
            this->lava_sprites.push_back(this->lava);
        }
    }
}
