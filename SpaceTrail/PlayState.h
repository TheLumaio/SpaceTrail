#pragma once
#include "GameState.h"
#include "LGui/LButton.h"

class PlayState :
	public GameState
{
private:
	/// background
	sf::RectangleShape background;

public:
	PlayState()=default;
	PlayState(Engine* e);
	~PlayState();

	void init(EventMap&);
	void leave();
	void update(float, sf::Event&);
	void render(sf::RenderWindow*);

};

