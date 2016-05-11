#include "option_tab.h"
#include "window.h"

using namespace sf;

OptionTab::OptionTab() : ScreenWait("", "")
{

}

OptionTab::~OptionTab()
{

}

void OptionTab::draw(RenderTarget &target, RenderStates states) const
{

}

void OptionTab::processEvent(Event &event, State &state)
{
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
        state = MENU;
}
