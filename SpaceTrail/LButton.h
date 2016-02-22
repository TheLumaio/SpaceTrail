#pragma once

#include "LWidget.h"

class LButton :
	public LWidget
{
private:
	sf::Texture up_tex;
	sf::Texture down_tex;
	sf::Sprite sprite;

	std::function<void()> callback;

	sf::Vector2i mpos;

	bool inBounds(sf::Vector2i);

public:
	LButton() = default;
	LButton(std::string, std::string, float=0, float=0);
	~LButton();

	void connect(std::function<void()>);
	void handleEvents(thor::ActionMap<std::string>&);
	void update();
	void render(sf::RenderWindow*);

};

