#include "stdafx.h"
#include "LLabel.h"

LLabel::LLabel(std::string text, float x, float y, int c, float w, std::string f) :
	text(text),
	x(x),
	y(y),
	w(w)
{
	font.loadFromFile(f);
	drawtext.setFont(font);
	drawtext.setString(text);
	drawtext.setPosition(sf::Vector2f(x + 12, y - ceil(c/1.3)));
	drawtext.setCharacterSize(c);
}

LLabel::~LLabel()
{
}

void LLabel::handleEvents(thor::ActionMap<std::string>&)
{

}

void LLabel::update()
{

}

void LLabel::render(sf::RenderWindow* context)
{
	sf::Vertex left[2] = {
		sf::Vertex(sf::Vector2f(x, y), sf::Color::Green),
		sf::Vertex(sf::Vector2f(x + 10, y), sf::Color::Green)
	};
	sf::Vertex right[2] = {
		sf::Vertex(sf::Vector2f(drawtext.getPosition().x + drawtext.getLocalBounds().width + 5, y), sf::Color::Green),
		sf::Vertex(sf::Vector2f(x + w, y), sf::Color::Green)
	};

	context->draw(left, 2, sf::Lines);
	context->draw(right, 2, sf::Lines);
	context->draw(drawtext);

}

void LLabel::setText(std::string text)
{
	this->text = text;
	drawtext.setString(text);
}
