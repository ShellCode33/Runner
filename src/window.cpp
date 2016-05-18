#include "window.h"
#include "const.h"

using namespace sf;
using namespace std;

WindowRunner::WindowRunner() : window(NULL), cursor(20.f), menu(*this), splash_screen(SPLASH_IMG, SPLASH_TEXT), game(*this), game_over(this, game)
{
    //On définit une view qui s'ajustera automatiquement à toutes les tailles d'écran
    this->reset(FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));

    assert(this->cursor_texture.loadFromFile(CURSOR_IMG));
    this->cursor.setTexture(this->cursor_texture);

    int i, j;
    for(i = 0; i < 5; i++)
        for(j = 0; j < 3; j++)
            this->cursor.addClip(IntRect(32*j, 32*i, 32, 32));
}

WindowRunner::~WindowRunner()
{
    if(this->window != nullptr)
        delete this->window;
}

void WindowRunner::create()
{
    // Récupère la résolution du bureau
    this->desktop = VideoMode::getDesktopMode();

    this->window = new RenderWindow(this->desktop, TITLE_WINDOW, Style::Fullscreen);
    this->setViewport(FloatRect(0.f, 0.f, 1.f, 1.f));
    this->window->setView(*this);
    this->state = SPLASH;

    this->splash_screen.setTextPosition(Vector2f((this->getSize().x - this->splash_screen.getTextWidth()) / 2, (this->getSize().y - this->splash_screen.getTextHeight()) / 1.2));
    this->game_over.setTextPosition(Vector2f((this->getSize().x / 15), (this->getSize().y / 2)));

    this->window->setFramerateLimit(FRAMERATE);
    //this->window->setVerticalSyncEnabled(false); //Performance issues

    this->window->setMouseCursorVisible(false);

    while(this->window->isOpen())
    {
        dispatchEvents();
        this->window->clear();

        this->cursor.update(); //On met à jour le curseur graphiquement

        switch(this->state)
        {
            case SPLASH:
                this->window->draw(this->splash_screen);
                break;

            case MENU:
                this->window->draw(this->menu);
                this->window->draw(this->cursor);
                break;

            case SURVIVAL:
            case CAMPAIGN:
                this->window->draw(*game.getView());
                game.update();
                break;

            case HIGH_SCORES:
                this->window->draw(this->high_scores_tab);
                break;

            case OPTIONS:
                this->window->draw(this->option_tab);
                this->window->draw(this->cursor);
                break;

            case ABOUT:
                this->about_tab.update();
                this->window->draw(this->about_tab);
                this->window->draw(this->cursor);
                break;

            case GAME_OVER:
                this->game_over.update();
                this->window->draw(this->game_over);
                this->window->draw(this->cursor);
                break;

            case EXIT:
                this->window->close();
                break;
        }

        this->window->display();
    }
}


void WindowRunner::dispatchEvents()
{
    Event event;

    while(this->window->pollEvent(event))
    {
        if(event.type == Event::Closed)
            this->window->close();

        switch(this->state)
        {
            case SPLASH:
                this->splash_screen.processEvent(event, this->state);
                break;

            case MENU:
                this->menu.processEvents(event);
                break;

            case SURVIVAL:
                game.getView()->processEvent(event);
                break;
            case CAMPAIGN:
                game.getView()->processEvent(event);
                break;

            case HIGH_SCORES:
                this->high_scores_tab.processEvent(event, this->state);
                break;

            case OPTIONS:
                this->option_tab.processEvent(event, this->state);
                break;

            case GAME_OVER:
                this->game_over.processEvent(event, this->state);
                break;

            case ABOUT:
                this->about_tab.processEvent(*this, event);
                break;

            default: break;
        }

        if(event.type == Event::MouseMoved)
        {
            Vector2i window_mouse_pos = Mouse::getPosition(*this->window);
            Vector2i mouse_pos = this->window->mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
            this->cursor.setPosition(mouse_pos.x, mouse_pos.y);
        }
    }
}

State WindowRunner::getState() const
{
    return this->state;
}

void WindowRunner::setState(const State &value)
{
    if(this->state == GAME_OVER)
    {
        //Si c'était un game_over d'où on vient, alors on écrit le score
        Utils::addScore(this->game.getModel()->getScore(), this->game.getModel()->getPseudo());
    }

    if(value == HIGH_SCORES)
    {
        this->high_scores_tab.update();
    }

    if(value == SURVIVAL || value == CAMPAIGN)
    {
        Utils::log("Launch game");
        launchGame();
    }

    this->state = value;
}

void WindowRunner::draw(const Drawable &drawable, const RenderStates &states) const
{
    this->window->draw(drawable, states);
}

RenderWindow & WindowRunner::getRender() const
{
  return *this->window;
}

void WindowRunner::launchGame()
{
    this->game.create();
}
