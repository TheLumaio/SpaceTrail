#pragma once

#include <SFML/Graphics.hpp>
#include <Thor/Input.hpp>

class LWidget
{
protected:
	float x, y, z;
	std::string _text;
public:
	LWidget();
	~LWidget();

	virtual void handleEvents(thor::ActionMap<std::string>&);
	virtual void update();
	virtual void render(sf::RenderWindow*);

	virtual void setText(std::string);
	virtual void setPosition(float, float) final;

};
