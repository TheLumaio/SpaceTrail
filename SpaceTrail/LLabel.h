#pragma once
#include "LWidget.h"

class LLabel :
	public LWidget
{
private:
	std::string text;
	float x, y, w;

	sf::Font font;
	sf::Text drawtext;

public:
	LLabel() = default;
	LLabel(std::string, float, float, int = 16, float = 200, std::string = "data/fonts/proggy.ttf");
	~LLabel();

	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);

	void setText(std::string);

};

