#include "SFML/Graphics.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include "SFML/Window/WindowStyle.hpp"
#include "customer/Customer.h"
#include "event/ActionMap.h"
#include "event/ActionTarget.h"
#include "multiply/multiply.h"
#include "nlohmann/json.hpp"
#include "resource/ResourceManager.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using json = nlohmann::json;

enum class PlayerInput { Up, Left, Right, Down, Click };

class Player {
public:
    Player(ActionTarget<PlayerInput>& actions) : actionTarget_(actions) {
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
        actionTarget_.bind(PlayerInput::Click, [this](const sf::Event& e) {
            sf::Vector2f pos = {float(e.mouseButton.x), float(e.mouseButton.y)};
            if (!shape_.getGlobalBounds().contains(pos)) return;

            shape_.setFillColor(sf::Color::Red);
        });
    }

    void update(float dt) {
        shape_.move(movement_ * 200.f * dt);
        movement_ = sf::Vector2f();
    }
    void draw(sf::RenderTarget& target) { target.draw(shape_); }

private:
    ActionTarget<PlayerInput>& actionTarget_;
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
    FloorStaff* staff = new Waiter();
    Customer customer("Bob", 4);
    customer.interact(*staff);

    ResourceManager<sf::Texture> textures;
    textures.load(0, "assets/hunny.png");

    ActionMap<PlayerInput> map;
    map.map(PlayerInput::Up, Action(sf::Keyboard::Up));
    map.map(PlayerInput::Down, Action(sf::Keyboard::Down));
    map.map(PlayerInput::Right, Action(sf::Keyboard::Right));
    map.map(PlayerInput::Left, Action(sf::Keyboard::Left));
    map.map(PlayerInput::Click, Action(sf::Mouse::Left, Action::Pressed));

    ActionTarget<PlayerInput> target(map);

    Player player(target);

    std::cout << "COS 214 - Final Project" << std::endl;
    std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;

    readAssetFile("demo_asset.json");
    sf::RenderWindow w(sf::VideoMode(1280, 720),
        "COS 214 Final Project",
        sf::Style::Default ^ sf::Style::Resize);

    sf::RectangleShape r({300, 200});
    sf::Sprite sprite(*textures.get(0));

    r.setPosition({10, 10});
    r.setFillColor(sf::Color(255, 0, 0));
    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();
    while (w.isOpen()) {
        sf::Event e;
        while (w.pollEvent(e)) {
            target.processEvent(e);
            if (e.type == sf::Event::EventType::Closed) {
                w.close();
            }
        }
        w.clear();
        float dt = clock.getElapsedTime().asSeconds() - lastTime;
        lastTime += dt;

        target.processEvents();
        player.update(dt);

        w.draw(sprite);

        player.draw(w);
        w.display();
        // rect.draw(w);
    }
}