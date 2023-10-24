#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "event/ActionMap.h"
#include "event/ActionTarget.h"
#include "multiply/multiply.h"
#include <corecrt_math.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

enum class PlayerInput { Up, Left, Right, Down };

class Player {
public:
    Player(const ActionMap<PlayerInput>& map) : actionTarget_(map) {
        shape_ = sf::RectangleShape({40, 40});
        shape_.setFillColor(sf::Color::Blue);
        shape_.setOrigin(16, 16);

        actionTarget_.bind(
            PlayerInput::Up, [this](const sf::Event&) { movement_.y -= 1; });
        actionTarget_.bind(
            PlayerInput::Left, [this](const sf::Event&) { movement_.x -= 1; });
        actionTarget_.bind(
            PlayerInput::Right, [this](const sf::Event&) { movement_.x += 1; });
        actionTarget_.bind(
            PlayerInput::Down, [this](const sf::Event&) { movement_.y += 1; });
    }

    void processEvents() {
        movement_ = sf::Vector2f();
        actionTarget_.processEvents();
        if (movement_.x != 0 || movement_.y != 0) {
            auto [x, y] = movement_;
            float mag = sqrtf(x * x + y * y);
            movement_.x /= mag;
            movement_.y /= mag;
        }
    }
    void update(float dt) { shape_.move(movement_ * 200.f * dt); }
    void draw(sf::RenderTarget& target) { target.draw(shape_); }

private:
    ActionTarget<PlayerInput> actionTarget_;
    sf::RectangleShape shape_;
    sf::Vector2f movement_;
};

void readAssetFile(const std::string& path) {
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);

    std::cout << data["name"].get<std::string>() << std::endl;
    std::cout << data["age"].get<int>() << std::endl;
}

int main() {
    ActionMap<PlayerInput> map;
    map.map(PlayerInput::Up, Action(sf::Keyboard::Key::Up));
    map.map(PlayerInput::Down, Action(sf::Keyboard::Key::Down));
    map.map(PlayerInput::Right, Action(sf::Keyboard::Key::Right));
    map.map(PlayerInput::Left, Action(sf::Keyboard::Key::Left));

    Player player(map);

    std::cout << "COS 214 - Final Project" << std::endl;
    std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;

    readAssetFile("demo_asset.json");
    sf::RenderWindow w(sf::VideoMode(800, 600), "COS 214 Final Project");

    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();
    while (w.isOpen()) {
        sf::Event e;
        while (w.pollEvent(e)) {
            if (e.type == sf::Event::EventType::Closed) {
                w.close();
            }
        }
        w.clear();
        float dt = clock.getElapsedTime().asSeconds() - lastTime;
        lastTime += dt;

        player.processEvents();
        player.update(dt);

        player.draw(w);
        w.display();
        // rect.draw(w);
    }
}