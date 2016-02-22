#include "stdafx.h"
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

	emap["reset"] = thor::Action(sf::Keyboard::R, thor::Action::PressOnce);

	font.loadFromFile("data/fonts/proggy.ttf");
	text.setFont(font);
	text.setCharacterSize(16);

	background.setFillColor(sf::Color(15, 15, 15));
	background.setSize(sf::Vector2f(1280, 720));

	for (int i = 0; i < 12; i++)
		output.push_back("wow" - rand() % 64);

}

void PlayState::leave() { }

void PlayState::update(float dt, sf::Event& event)
{
	if (m_engine->getEventMap().isActive("reset"))
	{
		output.clear();
		for (int i = 0; i < 12; i++)
			output.push_back("wow" - rand() % 64);
	}
}

void PlayState::render(sf::RenderWindow* context)
{
	context->draw(background);

	sf::Vertex line[2];
	sf::Vertex end[2];

	for (unsigned int i = 0; i < output.size(); i++)
	{
		text.setString(output[i]);
		text.setPosition(17, (float)i * 16.f);

		line[0] = sf::Vertex(sf::Vector2f(5.f, 10.f + i * 16.f), sf::Color::Green);
		line[1] = sf::Vertex(sf::Vector2f(15.f, 10.f + i * 16.f), sf::Color::Green);

		end[0] = sf::Vertex(sf::Vector2f(10.f + text.findCharacterPos(text.getString().getSize()-1).x, 10.f + i * 16.f), sf::Color::Green);
		end[1] = sf::Vertex(sf::Vector2f(200.f, 10.f + i * 16.f), sf::Color::Green);

		context->draw(line, 2, sf::PrimitiveType::Lines);
		context->draw(end, 2, sf::PrimitiveType::Lines);
		context->draw(text);
	}

}
