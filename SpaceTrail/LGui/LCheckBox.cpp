#include "LCheckBox.h"

LCheckBox::LCheckBox(std::string t, float x, float y, bool checked, float w) :
	checked(checked),
	x(x),
	y(y),
	w(w)
{
	// 14x14

	font.loadFromFile("data/fonts/proggy.ttf");
	text.setFont(font);
	text.setString(t);
	text.setPosition(sf::Vector2f(x + 28, y-5));
	text.setCharacterSize(16);
}

LCheckBox::~LCheckBox()
{
}

bool LCheckBox::isChecked()
{
	return checked;
}

bool LCheckBox::inBounds()
{
	return (mpos.x > x && mpos.x < x + 14 && mpos.y > y && mpos.y < y + 14);
}

void LCheckBox::handleEvents(thor::ActionMap<std::string>& emap)
{
	if (emap.isActive("click_left")) if (inBounds()) checked = !checked;
}

void LCheckBox::update()
{

}

void LCheckBox::render(sf::RenderWindow* context)
{
	mpos = sf::Mouse::getPosition(*context);

	sf::RectangleShape outer(sf::Vector2f(14, 14));
	outer.setPosition(x, y);
	outer.setFillColor(sf::Color::Transparent);
	outer.setOutlineColor(sf::Color(0, 255, 255));
	outer.setOutlineThickness(1);

	sf::RectangleShape inner(sf::Vector2f(10, 10));
	inner.setPosition(x + 2, y + 2);
	inner.setFillColor(sf::Color(128, 128, 128));

	sf::RectangleShape highlight(sf::Vector2f(12, 12));
	highlight.setPosition(x + 1, y + 1);
	highlight.setFillColor(sf::Color::Transparent);
	highlight.setOutlineColor(sf::Color(175, 175, 175));
	highlight.setOutlineThickness(1);

	sf::Vertex left[2] = {
		sf::Vertex(sf::Vector2f(x + 17, y + 7), sf::Color(0, 255, 255)),
		sf::Vertex(sf::Vector2f(x + 17+8, y + 7), sf::Color(0, 255, 255))
	};

	sf::Vertex right[2] = {
		sf::Vertex(sf::Vector2f(text.getPosition().x + text.getLocalBounds().width + 5, y + 7), sf::Color(0, 255, 255)),
		sf::Vertex(sf::Vector2f(x + w, y + 7), sf::Color(0, 255, 255))
	};


	context->draw(left, 2, sf::Lines);
	context->draw(right, 2, sf::Lines);

	context->draw(text);
	context->draw(outer);

	if (isChecked())
		context->draw(inner);
	if (inBounds())
		context->draw(highlight);

}
