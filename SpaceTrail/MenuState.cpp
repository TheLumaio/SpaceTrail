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
	gui->addWidget(new LLabel("Space Trail", 1280/2-300/2, 50, A_CENTER, 16*2, 300));

	// demo

	gui->addWidget(new LCheckBox("Test box", 100, 100, false, 140));
	gui->addWidget(new LCheckBox("Another box", 100, 125, false, 140));
	gui->addWidget(new LCheckBox("One more", 100, 150, false, 140));
	gui->addWidget(new LCheckBox("Aaaand another", 100, 175, false, 140));

	gui->addWidget(new LLabel("Demo Label : LEFT", 100, 250, A_LEFT));
	gui->addWidget(new LLabel("Demo Label : CENTER", 100, 275, A_CENTER));
	gui->addWidget(new LLabel("Demo Label : RIGHT", 100, 300, A_RIGHT));

	gui->addWidget(new LButton("Demo Button", 100, 375, 200));

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
	context->clear(sf::Color(25, 25, 25));
	gui->render(context);
}
