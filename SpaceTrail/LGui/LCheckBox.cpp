#include "LCheckBox.h"

LCheckBox::LCheckBox(std::string text, float x, float y, bool checked, float w) :
	checked(checked),
	x(x),
	y(y),
	w(w)
{
}

LCheckBox::~LCheckBox()
{
}

bool LCheckBox::isChecked()
{
	return checked;
}

void LCheckBox::handleEvents(thor::ActionMap<std::string>& emap)
{

}

void LCheckBox::update()
{

}

void LCheckBox::render(sf::RenderWindow* context)
{

}
