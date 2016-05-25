#include "game_view.h"
#include "window.h"

using namespace std;
using namespace sf;

GameView::GameView(WindowRunner &window, GameModel &model, Player &player, list<Chunk *> &chunks, std::list<Entity *> &entities) : window(window), game_model(model), fire(20.0), fire2(20.0), lava(20.0), player(player), chunks(chunks), entities(entities), pause(false), timer_police_circle1(80.), timer_police_circle2(50.), display_police_alarm1(false), display_police_alarm2(false)
{
    assert(this->font.loadFromFile(ONTHEMOVE_TTF));

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

    assert(this->texture_score.loadFromFile(SCORE_BG));
    this->score_background.setTexture(this->texture_score);
    this->score_background.setPosition(VIEW_WIDTH - this->score_background.getLocalBounds().width - 20, VIEW_HEIGHT - (GROUND_DEFAULT + this->score_background.getLocalBounds().height) / 2);//-20 pour l'espace depuis l'écran

    this->score_display.setFont(this->font);
    this->score_display.setCharacterSize(50);
    this->score_display.setString("Score: 0");
    this->score_display.setPosition(VIEW_WIDTH - (this->score_background.getLocalBounds().width + this->score_display.getLocalBounds().width) / 2 - 20, VIEW_HEIGHT - (GROUND_DEFAULT + this->score_display.getLocalBounds().height + 30) / 2); //-20 et + 15 pour l'espace depuis l'écran


    assert(this->texture_life.loadFromFile(HEART_IMG));
    this->life_heart.setTexture(this->texture_life);

    this->life_display.setFont(this->font);
    this->life_display.setCharacterSize(30);
    this->life_display.setColor(Color(0, 0, 0, 255));
    this->life_display.setStyle(Text::Bold);
    this->life_display.setString("100");

    this->life_heart.setPosition(VIEW_WIDTH - this->score_background.getLocalBounds().width - 20 - this->life_heart.getLocalBounds().width - 50, VIEW_HEIGHT - (GROUND_DEFAULT + this->life_heart.getGlobalBounds().height) / 2); //-20 espace écran -50 espace entre le score et le coeur de vie
    this->life_display.setPosition(VIEW_WIDTH - this->score_background.getLocalBounds().width - 20 - this->life_heart.getLocalBounds().width - 50 + (this->life_heart.getLocalBounds().width - this->life_display.getLocalBounds().width) / 2 , VIEW_HEIGHT - (GROUND_DEFAULT + this->life_heart.getGlobalBounds().height) / 2 + this->life_display.getLocalBounds().height / 2);

    assert(this->lava_texture.loadFromFile(LAVA_IMG));
    this->lava.setTexture(this->lava_texture);

    for(i = 0; i < 7; i++)
        this->lava.addClip(IntRect(130*i, 112, 128, 128));

    for(i = 0; i < 4; i++)
        this->lava.addClip(IntRect(130*i, 114+128, 128, 128));

    this->lava.setOffset(2, 2);

    this->pause_text.setFont(this->font);
    this->pause_text.setCharacterSize(80);
    this->pause_text.setColor(Color(255, 255, 255, 255));
    this->pause_text.setString("PAUSE");
    this->pause_text.setPosition(Vector2f((VIEW_WIDTH - this->pause_text.getLocalBounds().width) / 2, VIEW_HEIGHT / 3));

    assert(this->blur.loadFromFile(BLUR_EFFECT_PATH, Shader::Fragment));
    this->blur.setParameter("texture", sf::Shader::CurrentTexture);
    this->blur.setParameter("blur_radius", 0.003f);

    this->texture_pause.loadFromImage(this->window.getRender().capture());
}

GameView::~GameView()
{

}

void GameView::draw(RenderTarget& target, RenderStates states) const
{
    for(Chunk *c : this->chunks)
        c->draw(target, states);

    for(Entity* c : this->entities)
        c->draw(target, states);

    if(!this->player.getModel()->isDead())
        target.draw(*this->player.getView(), states);

    else
        target.draw(*this->player.getView()->getDeadAnim(), states);

    target.draw(this->fire, states);
    target.draw(this->fire2, states);

    target.draw(this->score_background, states);
    target.draw(this->score_display, states);

    target.draw(this->life_heart, states);
    target.draw(this->life_display, states);

    for(const Sprite& s : this->lava_sprites)
        target.draw(s, states);

    if(this->game_model.getPolice() != nullptr)
    {
        PoliceModel *police = this->game_model.getPolice()->getModel();

        if(police->getPosition().first > VIEW_WIDTH)
        {
            CircleShape circle;
            circle.setOrigin(50, 50);
            circle.setRadius(50);

            if(this->display_police_alarm1)
            {
                circle.setFillColor(Color(255, 0, 0, 100));
                circle.setPosition(VIEW_WIDTH + 20, police->getY());
                target.draw(circle);
            }

            if(this->display_police_alarm2)
            {
                circle.setFillColor(Color(0, 0, 255, 150));
                circle.setPosition(VIEW_WIDTH + 20, police->getY() + 50); //10 valeur arbitraire afin de créer un décalage entre les 2 rectangles
                target.draw(circle);
            }
        }
    }

    //On dessine un rectangle rouge transparent sur tout l'écran pour donner l'impression que le joueur saigne
    if(this->player.getModel()->getLife() < 100)
    {
        RectangleShape rect;
        rect.setFillColor(Color(255, 0, 0, 50 - 50 * this->player.getModel()->getLife() / 100)); //100 est la vita de base
        rect.setPosition(0, 0);
        rect.setSize(Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
        target.draw(rect);
    }

    if(this->pause)
    {
        states.shader = &this->blur;
        target.draw(this->sprite_pause, states);

        RectangleShape rect;
        rect.setFillColor(Color(0, 0, 0, 100));
        rect.setPosition(0, 0);
        rect.setSize(Vector2f(VIEW_WIDTH, VIEW_HEIGHT));
        target.draw(rect);

        target.draw(this->pause_text);
    }
}

void GameView::processEvent(Event &event)
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
    {
        this->pause = !this->pause;

        if(this->pause)
        {
            this->texture_pause.update(this->window.getRender());
            this->sprite_pause.setTexture(this->texture_pause);
            this->sprite_pause.setScale(VIEW_WIDTH / this->sprite_pause.getLocalBounds().width, VIEW_HEIGHT / this->sprite_pause.getLocalBounds().height);
        }
    }

    if(!this->pause)
        this->player.getView()->processEvents(this->window, event);
}

void GameView::update()
{
    if(!this->pause)
    {
        this->player.getView()->update(); //On met à jouer l'affichage du joueur
        this->fire.update(); //On met l'animation du feu à jour
        this->fire2.update();
        this->lava.update();

        this->fire.setPosition(FIRE_DEFAULT_POS + this->game_model.getFireOffset(), this->fire.getPosition().y);
        this->fire2.setPosition(FIRE_DEFAULT_POS + this->game_model.getFireOffset(), this->fire2.getPosition().y);

        //On met à jour l'affichage du score
        this->score_display.setString("Score: " + to_string(this->game_model.getScore()));
        this->score_display.setPosition(VIEW_WIDTH - (this->score_background.getLocalBounds().width + this->score_display.getLocalBounds().width) / 2 - 20, VIEW_HEIGHT - (GROUND_DEFAULT + this->score_display.getLocalBounds().height + 30) / 2); //-20 et + 15 pour l'espace depuis l'écran


        //On met à jour l'affichage de la vie
        this->life_display.setString(to_string(this->player.getModel()->getLife()));
        this->life_display.setPosition(VIEW_WIDTH - this->score_background.getLocalBounds().width - 20 - this->life_heart.getLocalBounds().width - 50 + (this->life_heart.getLocalBounds().width - this->life_display.getLocalBounds().width) / 2 , VIEW_HEIGHT - (GROUND_DEFAULT + this->life_heart.getGlobalBounds().height) / 2 + this->life_display.getLocalBounds().height / 2);

        //Lave
        this->lava_sprites.clear(); //TROP LOURD, A MODIFIER POUR OPTI
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


        //On fait clignoter l'alarme de la police
        if(this->timer_police_circle1.isFinish())
        {
            this->display_police_alarm1 = !this->display_police_alarm1;
            this->timer_police_circle1.reset();
        }

        if(this->timer_police_circle2.isFinish())
        {
            this->display_police_alarm2 = !this->display_police_alarm2;
            this->timer_police_circle2.reset();
        }
    }
}
bool GameView::isPaused() const
{
    return this->pause;
}

void GameView::setPause(bool value)
{
    this->pause = value;
}

