#pragma once

#include "LWidget.h"

class LGUI
{
private:
	std::vector<LWidget*> m_widgets;

public:
	LGUI();
	~LGUI();

	void clearWidgets();
	void eraseWidget(std::string);

	void addWidget(LWidget*);
	LWidget* getWidget(std::string);

	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);

};

