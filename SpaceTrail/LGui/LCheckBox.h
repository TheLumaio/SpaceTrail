#pragma once
#include "LWidget.h"

class LCheckBox :
	public LWidget
{
private:
	bool checked;
	float x, y, w;

public:
	LCheckBox() = default;
	LCheckBox(std::string, float, float, bool = false, float = 100);
	~LCheckBox();

	bool isChecked();

	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);
};

