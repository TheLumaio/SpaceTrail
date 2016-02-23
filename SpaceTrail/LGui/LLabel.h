#pragma once
#include "LWidget.h"

enum ALIGN
{
	A_LEFT,
	A_RIGHT,
	A_CENTER
};

class LLabel :
	public LWidget
{
private:
	float w;

	sf::Font font;
	sf::Text drawtext;

	ALIGN align;

	void drawLeft(sf::RenderWindow*);
	void drawRight(sf::RenderWindow*);
	void drawCenter(sf::RenderWindow*);

public:
	LLabel() = default;
	LLabel(std::string, float, float, ALIGN = A_LEFT, int = 16, float = 200, std::string = "data/fonts/proggy.ttf");
	~LLabel();

	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);

	void setText(std::string);

};

