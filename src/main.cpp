#include "Menu/Menu.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/View.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Window/WindowStyle.hpp"

#include "core/TerminalApp.h"
#include "customer/Customer.h"
#include "event/ActionMap.h"
#include "event/ActionTarget.h"
#include "floor/CustomerIterator.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"
#include "multiply/multiply.h"
#include "nlohmann/json.hpp"
#include "order/NullOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "resource/ResourceManager.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"
#include "views/FloorView.h"
#include "views/TablePresenter.h"
#include "views/TableView.h"

#include "nlohmann/json.hpp"
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

void menuTest() {
    Menu* menu = new Menu();
    menu->initMenu();

    std::vector<Item> items = menu->getAllItems();
    for (auto& item : items) {
        std::cout << "[DEBUG] Item OUT: ";
        std::cout << item.getName() << std::endl;
        std::cout << item.getPrice() << std::endl;
        std::cout << item.getRestrictions() << std::endl;
    }
}

int main() {

    menuTest();

    TerminalApp app;
    app.run();
    return 0;

    ResourceManager<sf::Texture, FloorView::SpriteType> tableSprites;
    tableSprites.load(FloorView::SingleTable, "assets/textures/table.png");

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

    // TableView table(tableSprites);
    // TablePresenter presenter(table, w);
    // table.position({100, 100});

    r.setPosition({10, 10});
    r.setFillColor(sf::Color(255, 0, 0));
    sf::Clock clock;
    float lastTime = clock.getElapsedTime().asSeconds();

    FloorView view(12, 7, tableSprites);
    view.position({10, 10});
    view.placeTable(1, 1);
    view.placeTable(2, 1);
    view.placeTable(3, 1);

    while (w.isOpen()) {
        // Handle Events
        sf::Event e;
        while (w.pollEvent(e)) {
            // table.onEvent(e);
            target.processEvent(e);
            if (e.type == sf::Event::EventType::Closed) {
                w.close();
            }
        }
        target.processEvents();

        // Time-based update
        float dt = clock.getElapsedTime().asSeconds() - lastTime;
        lastTime += dt;

        player.update(dt);
        // presenter.update(dt);

        // Render window
        w.clear();

        w.draw(sprite);
        player.draw(w);
        // table.draw(w);
        view.draw(w);

        w.display();
        // rect.draw(w);
    }
}