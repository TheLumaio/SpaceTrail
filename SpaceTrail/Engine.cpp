#include "Engine.h"

Engine::Engine(int width, int height, std::string title) :
	m_width(width),
	m_height(height)
{
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title, sf::Style::Close);

	m_emap["close"] = thor::Action(sf::Event::Closed); // default clost event;
	// other default events
	m_emap["click_left"] = thor::Action(sf::Mouse::Left, thor::Action::PressOnce);
	m_emap["click_right"] = thor::Action(sf::Mouse::Right, thor::Action::PressOnce);
	m_emap["hold_left"] = thor::Action(sf::Mouse::Left, thor::Action::Hold);
	m_emap["hold_right"] = thor::Action(sf::Mouse::Right, thor::Action::Hold);

}

void Engine::start()
{
	sf::Event event;
	while (m_window->isOpen())
	{
		m_emap.clearEvents();
		while (m_window->pollEvent(event))
			m_emap.pushEvent(event);

		if (m_emap.isActive("close"))
			m_window->close();

		if (!m_states.empty())
		{
			if (!m_states.top()->initialized)
			{
				m_states.top()->init(m_emap);
				m_states.top()->initialized = true;
			}
		}

		if (!m_states.empty())
			m_states.top()->update(1.f / 512.f, event);

		m_window->clear();

		if (!m_states.empty())
			m_states.top()->render(m_window);

		m_window->display();
	}
}

void Engine::setState(GameState* state)
{
	printf("new state: ");
	if (!m_states.empty())
	{
		printf(" !empty! ");
		m_states.top()->leave();
		delete m_states.top();
		m_states.top() = nullptr;
		m_states.pop();
	}
	printf("clear.\n");
	m_states.push(state);
}
void Engine::quit()
{
	m_window->close();
}

EventMap& Engine::getEventMap()
{
	return m_emap;
}

sf::RenderWindow* Engine::getContext()
{
	return m_window;
}
