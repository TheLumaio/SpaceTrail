#include "stdafx.h"
#include "LButton.h"


LButton::LButton(std::string t, float x, float y, float w, int c, std::string f) :
	x(x),
	y(y),
	w(w),
	c1(c),
	c2(c * 2),
	c3(c + c/2)
{
	callback = [&]() {}; // default callback. does nothing.

	font.loadFromFile(f);
	text.setFont(font);
	text.setString(t);
	text.setCharacterSize(c);


}

LButton::~LButton()
{
}

bool LButton::inBounds(sf::Vector2i m)
{
	float s_l = text.getPosition().x;
	float s_r = text.getPosition().x + text.getGlobalBounds().width;
	float s_t = text.getPosition().y;
	float s_b = text.getPosition().y + text.getCharacterSize() + 10;
	return (m.x > s_l && m.x < s_r && m.y > s_t && m.y < s_b);
}

void LButton::connect(std::function<void()> callback)
{
	this->callback = callback;
}

void LButton::handleEvents(thor::ActionMap<std::string>& emap)
{
	if (emap.isActive("click_left")) if (inBounds(mpos)) callback();
	
	if (inBounds(mpos))
	{
		if (emap.isActive("hold_left") && inBounds(mpos))
			text.setCharacterSize(c3);
		else
			text.setCharacterSize(c2);
	}
	else
		text.setCharacterSize(c1);

	float tw = text.getGlobalBounds().width;
	text.setPosition(floor(x + ((w / 2) - (tw / 2))) + 2, y - ceil(text.getCharacterSize() / 1.3));
	// how about them nests tho
}

void LButton::update()
{

	float tw = text.getGlobalBounds().width;
	text.setPosition(floor(x + ((w / 2) - (tw / 2))) + 2, y - ceil(text.getCharacterSize() / 1.3));
}

void LButton::render(sf::RenderWindow* context)
{
	mpos = sf::Mouse::getPosition(*context);

	float tw = text.getGlobalBounds().width;
	float z = (x + ((w / 2) - (tw / 2)));

	sf::Vertex left[2] = {
		sf::Vertex(sf::Vector2f(x, y), sf::Color(0, 255, 255)),
		sf::Vertex(sf::Vector2f(z, y), sf::Color(0, 255, 255))
	};
	sf::Vertex right[2] = {
		sf::Vertex(sf::Vector2f(z + tw + 4, y), sf::Color(0, 255, 255)),
		sf::Vertex(sf::Vector2f(x + w, y), sf::Color(0, 255, 255))
	};

	context->draw(left, 2, sf::Lines);
	context->draw(right, 2, sf::Lines);
	context->draw(text);
}
