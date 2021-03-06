#pragma once

#include <iostream>
#include <vector>
#include "Injury.h"
#include "NameGenerator.h"

struct Crew
{
	std::vector<Injury*> injuries;

	std::string name_first;
	std::string name_last;
	double health, dexterity, hunger, thirst;

	void calculate()
	{
		for each(Injury* i in injuries)
		{
			health    -= i->health;
			dexterity -= i->dexterity;
			hunger    -= i->hunger;
			thirst    -= i->thirst;
		}
	}

	Crew()
	{
		name_first = NameGen::NameGen();
		name_last = NameGen::NameGen();
	}

};
