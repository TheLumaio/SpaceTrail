#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include "NameGenerator.h"

namespace NameGen
{

	std::vector<std::string> NamePrefix = {
		"bel", "nar", "xan",
		"bell", "natr", "ev",
		"adur", "aes", "anim", "apoll", "imac",
		"educ", "equis", "extr", "guius", "hann",
		"equi", "amora", "hum", "iace", "ille",
		"inept", "iuv", "obe", "ocul", "orbis"
	};

	std::vector<std::string> NameStems = {
	};

	std::vector<std::string> NameSuffix = {
		"us", "ix", "ox", "ith",
		"ath", "um", "ator", "or", "axia",
		"imus", "ais", "itur", "orex", "o"
		"y"
	};

	std::string NameGen()
	{
		std::ostringstream ss;
		std::string PlayerName;
		
		ss << NamePrefix[(rand() % NamePrefix.size())];
		//ss << NameStems[(rand() % NameStems.size())];
		ss << NameSuffix[(rand() % NameSuffix.size())];

		PlayerName = ss.str();
		PlayerName[0] = std::toupper(PlayerName[0]);

		return PlayerName;
	}

}
