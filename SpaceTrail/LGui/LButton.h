#pragma once

#include "LWidget.h"

class LButton :
	public LWidget
{
private:

	std::function<void()> callback;
	sf::Vector2i mpos;

	bool inBounds(sf::Vector2i);

	sf::Font font;
	sf::Text text;

	float x, y, w;
	int c1, c2, c3;

public:
	LButton() = default;
	LButton(std::string, float, float, float = 150, int = 16, std::string = "data/fonts/proggy.ttf");
	~LButton();

	void connect(std::function<void()>);
	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);

};

