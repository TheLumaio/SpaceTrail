#include "LWidget.h"

LWidget::LWidget() { }
LWidget::~LWidget() { }

void LWidget::handleEvents(thor::ActionMap<std::string>&) { }
void LWidget::update() { }
void LWidget::render(sf::RenderWindow*) { }

void LWidget::setText(std::string text)
{
	_text = text;
}

void LWidget::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}
