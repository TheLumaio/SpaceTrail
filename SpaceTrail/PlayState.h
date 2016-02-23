#pragma once
#include "GameState.h"
#include "LGui/LGUI.h"
#include "LGui/LCheckBox.h"
#include "LGui/LLabel.h"
#include "Crew.h"

struct HireOption
{
	Crew* crew;
	LCheckBox* hire;

	HireOption(float x, float y, float w)
	{
		crew = new Crew();
		hire = new LCheckBox(crew->name_first + " " + crew->name_last, x, y, false, 175);
	}
};

class PlayState :
	public GameState
{
private:
	std::vector<HireOption*> hirecrew;

	LGUI* gui;

public:
	PlayState()=default;
	PlayState(Engine* e);
	~PlayState();

	void init(EventMap&);
	void leave();
	void update(float, sf::Event&);
	void render(sf::RenderWindow*);

};

