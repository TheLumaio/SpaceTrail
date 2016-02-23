#include "../stdafx.h"
#include "LGUI.h"

LGUI::LGUI()
{
}

LGUI::~LGUI()
{
}

void LGUI::clearWidgets()
{
	m_widgets.clear();
}

void LGUI::eraseWidget(std::string id)
{
	//m_widgets.erase(id);
}

void LGUI::addWidget(LWidget* widget)
{
	m_widgets.emplace_back(widget);
}

LWidget* LGUI::getWidget(std::string id)
{
	return nullptr;
}

void LGUI::handleEvents(thor::ActionMap<std::string>& emap)
{
	for each(auto widget in m_widgets)
		widget->handleEvents(emap);
}

void LGUI::update()
{
	for each(auto widget in m_widgets)
		widget->update();
}

void LGUI::render(sf::RenderWindow* context)
{
	for each(LWidget* widget in m_widgets)
		widget->render(context);
}
