#include "Game.h"
#include "game/Game.h"
#include "game/Map.h"

Game::Game() { this->map_ = new Map(); }
Game::~Game() { delete map_; }
void Game::printDebug() const { this->map_->DebugPrint(); }