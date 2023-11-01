#pragma once
#include "Map.h"
#include "SFML/Graphics.hpp"
#include "game/Map.h"
#include "resource/ResourceManager.h"

class Game {
public:
    Game();
    ~Game();
    void printDebug() const;
    void GameDraw();
    void DrawMap();

protected:
private:
    Map* map_;
    sf::RenderWindow window_;
    ResourceManager<sf::Texture> textures;
    // list of customers
    // list of employees
};