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
	srand((unsigned int)time(NULL));
	printf("init\n");

}

void PlayState::leave() { }

void PlayState::update(float dt, sf::Event& event)
{

}

void PlayState::render(sf::RenderWindow* context)
{
	context->clear(sf::Color(25, 25, 25));

}
