#pragma once

#include <iostream>
#include <stack>
#include "GameState.h"

typedef thor::ActionMap<std::string> EventMap;

class GameState;

class Engine
{
private:

	sf::RenderWindow* m_window;
	EventMap m_emap;

	int m_width, m_height;

	std::stack<GameState*> m_states;

public:
	Engine(int=1280, int=720, std::string="Game Title");
	~Engine()=default;

	void start();
	void setState(GameState*);
	void quit();

	EventMap& getEventMap();
	sf::RenderWindow* getContext();
};

