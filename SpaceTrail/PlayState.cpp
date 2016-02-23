#include "PlayState.h"

PlayState::PlayState(Engine* e) :
	GameState(e)
{
}

PlayState::~PlayState()
{
}

void PlayState::init(EventMap& emap)
{
	gui = new LGUI();

	srand((unsigned int)time(NULL));
	printf("init\n");

	gui->addWidget(new LLabel("Select crew to hire. Max 5", 10, 10, A_CENTER));

	for (int i = 0; i < 10; i++)
	{
		HireOption* ho = new HireOption(10, 25 + i * 28, 0);
		hirecrew.emplace_back(ho);
		gui->addWidget(ho->hire);
	}

}

void PlayState::leave() { }

void PlayState::update(float dt, sf::Event& event)
{
	gui->handleEvents(m_engine->getEventMap());
	gui->update();
}

void PlayState::render(sf::RenderWindow* context)
{
	context->clear(sf::Color(25, 25, 25));
	if (gui != nullptr)
		gui->render(context);
}
