#pragma once
#include "LWidget.h"

class LCheckBox :
	public LWidget
{
private:
	bool checked;
	float w;

	sf::Font font;
	sf::Text text;

	sf::Vector2i mpos;
	
	bool inBounds();

public:
	LCheckBox() = default;
	LCheckBox(std::string, float, float, bool = false, float = 125);
	~LCheckBox();

	bool isChecked();

	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);
};

