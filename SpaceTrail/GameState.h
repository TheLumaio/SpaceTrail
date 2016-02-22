#pragma once

#include <iostream>
#include "Engine.h"

typedef thor::ActionMap<std::string> EventMap;

class Engine;

class GameState
{
protected:
	Engine* m_engine;

public:
	bool initialized = false;

	GameState();
	GameState(Engine*);
	~GameState();

	virtual void init(EventMap&);
	virtual void leave();
	virtual void update(float, sf::Event&);
	virtual void render(sf::RenderWindow*);

};

