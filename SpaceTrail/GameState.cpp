#include "GameState.h"


GameState::GameState() : initialized(false) { }
GameState::GameState(Engine* e) : initialized(false) { m_engine = e; }
GameState::~GameState() {}

void GameState::init(EventMap&) {}
void GameState::leave() {}
void GameState::update(float, sf::Event&) {}
void GameState::render(sf::RenderWindow*) {}
