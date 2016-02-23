// SpaceTrail.cpp : Defines the entry point for the console application.
//

#include "Engine.h"
#include "MenuState.h"
#include "NameGenerator.h"

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		std::cout << NameGen::NameGen() << " " << NameGen::NameGen()[0] << ". " << NameGen::NameGen() << std::endl;
	std::cout << std::endl << std::endl;

	Engine* engine = new Engine(1280, 720, "Space Trail");
	engine->setState(new MenuState(engine));
	engine->start();

	return 0;
		
}
