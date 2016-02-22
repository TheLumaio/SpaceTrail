// SpaceTrail.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include "MenuState.h"

int main()
{

	Engine* engine = new Engine(1280, 720, "Space Trail");
	engine->setState(new MenuState(engine));
	engine->start();

	return 0;
		
}
