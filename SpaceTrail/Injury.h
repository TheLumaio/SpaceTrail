#pragma once

struct Injury
{
	double health, dexterity, hunger, thirst;
	Injury(int h1 = 0, int d = 0, int h2 = 0, int t = 0) :
		health(h1),
		dexterity(d),
		hunger(h2),
		thirst(t)
	{ }
};

// TODO: write some injuries.
