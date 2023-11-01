#include "Game.h"
#include "resource/ResourceManager.h"

Game::Game() {
    this->textures.load(0, "assets/textures/floor1.png");
    this->textures.load(1, "assets/textures/entrance.png");
    this->textures.load(2, "assets/textures/waiter.png");
    this->textures.load(3, "assets/textures/wall.png");
    this->map_ = new Map();
}
Game::~Game() { delete map_; }
void Game::printDebug() const { this->map_->DebugPrint(); }
void Game::DrawMap() {
    sf::Event e;
    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    float lastTime = clock.getElapsedTime().asSeconds();

    while (window.isOpen()) {
        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::EventType::Closed) {
                window.close();
            }
        }
        window.clear();
        float dt = clock.getElapsedTime().asSeconds() - lastTime;
        lastTime += dt;
        this->map_->draw(window, this->textures);
        window.display();
    }
}
