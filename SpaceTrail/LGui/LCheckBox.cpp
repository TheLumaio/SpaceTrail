#include "stdafx.h"
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
