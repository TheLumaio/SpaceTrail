#pragma once
#include "GameState.h"
#include "PlayState.h"
#include "LGUI.h"
#include "LButton.h"

class MenuState :
	public GameState
{
private:
	/// ui
	LButton* start;
	LButton* options;
	LButton* quit;

	LGUI* gui;

public:
	MenuState() = default;
	MenuState(Engine*);
	~MenuState();

	void init(EventMap&);
	void leave();
	void update(float, sf::Event&);
	void render(sf::RenderWindow*);

};

