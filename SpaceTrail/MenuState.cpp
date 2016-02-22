#include "stdafx.h"
#include "MenuState.h"

#define and &&
#define or ||

MenuState::MenuState(Engine* e) :
	GameState(e)
{
}


MenuState::~MenuState()
{
}


void MenuState::init(EventMap& emap)
{
	start = new LButton("data/images/start_up.png", "data/images/start_down.png", 1280 / 2 - 128 / 2, 100);
	options = new LButton("data/images/options_up.png", "data/images/options_down.png", 1280 / 2 - 128 / 2, 166);
	quit = new LButton("data/images/quit_up.png", "data/images/quit_down.png", 1280 / 2 - 128 / 2, 166 + 66);

	start->connect([&]() { m_engine->setState(new PlayState(m_engine)); });
	quit->connect([&]() { m_engine->quit(); });

	gui = new LGUI();
	gui->addWidget(start);
	gui->addWidget(options);
	gui->addWidget(quit);

}

void MenuState::leave()
{ }

void MenuState::update(float dt, sf::Event& event)
{
	gui->handleEvents(m_engine->getEventMap());
	gui->update();
}

void MenuState::render(sf::RenderWindow* context)
{
	gui->render(context);
}
