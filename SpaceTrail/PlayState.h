#pragma once
#include "GameState.h"
#include "LButton.h"

class PlayState :
	public GameState
{
private:
	/// background
	sf::RectangleShape background;
	
	/// out
	std::vector<std::string> output;

	/// temp text
	sf::Font font;
	sf::Text text;

public:
	PlayState()=default;
	PlayState(Engine* e);
	~PlayState();

	void init(EventMap&);
	void leave();
	void update(float, sf::Event&);
	void render(sf::RenderWindow*);

};

