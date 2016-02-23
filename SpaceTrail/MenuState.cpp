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
	start = new LButton("Start", 1280/2-75, 100);
	options = new LButton("Options", 1280/2-75, 150);
	quit = new LButton("Quit", 1280/2-75, 200);

	start->connect([&]() { m_engine->setState(new PlayState(m_engine)); });
	quit->connect([&]() { m_engine->quit(); });

	gui = new LGUI();
	gui->addWidget(start);
	gui->addWidget(options);
	gui->addWidget(quit);
	gui->addWidget(new LLabel("Space Trail", 1280/2-300/2, 50, 16*2, 300));

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
