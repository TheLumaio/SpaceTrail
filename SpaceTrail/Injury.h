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

const Injury BrokenArm        = Injury(0, 10, 0, 0);
const Injury BrokenLeg        = Injury(0, 20, 0, 0);
const Injury InternalBleeding = Injury(5, 10, 0, 0);
const Injury SpaceDysentery   = Injury(10, 20, 0, 0);
