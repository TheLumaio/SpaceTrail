#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Input.hpp>

class LWidget
{
public:
	LWidget();
	~LWidget();

	virtual void handleEvents(thor::ActionMap<std::string>&);
	virtual void update();
	virtual void render(sf::RenderWindow*);

};
