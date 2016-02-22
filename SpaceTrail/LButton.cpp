#include "stdafx.h"
#include "LButton.h"


LButton::LButton(std::string up, std::string down, float x, float y) // down = hover
{
	up_tex.loadFromFile(up);
	down_tex.loadFromFile(down);

	sprite.setTexture(up_tex);
	sprite.setPosition(x, y);

	callback = [&]() {};

}

LButton::~LButton()
{
}

bool LButton::inBounds(sf::Vector2i m)
{
	float s_l = sprite.getPosition().x;
	float s_r = sprite.getPosition().x + sprite.getLocalBounds().width;
	float s_t = sprite.getPosition().y;
	float s_b = sprite.getPosition().y + sprite.getLocalBounds().height;

	return (m.x > s_l && m.x < s_r && m.y > s_t && m.y < s_b);
}

void LButton::connect(std::function<void()> callback)
{
	this->callback = callback;
}

void LButton::handleEvents(thor::ActionMap<std::string>& emap)
{
	if (emap.isActive("click_left")) if (inBounds(mpos)) callback();
	// how about them nests tho
}

void LButton::update()
{
	printf("%d : %d\r", mpos.x, mpos.y);

	if (inBounds(mpos))
		sprite.setTexture(down_tex);
	else
		sprite.setTexture(up_tex);
}

void LButton::render(sf::RenderWindow* context)
{
	mpos = sf::Mouse::getPosition(*context);
	context->draw(sprite);
}
