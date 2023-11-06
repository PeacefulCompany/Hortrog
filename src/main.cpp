#include "menu/Menu.h"

#include "core/TerminalApp.h"
#include "customer/Customer.h"
#include "demo/FloorDemo.h"
#include "floor/CustomerIterator.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"
#include "nlohmann/json.hpp"
#include "order/NullOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "resource/ResourceManager.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"

#include "core/Timer.h"
#include "subsystem/Meals/Meal.h"

#include "nlohmann/json.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "subsystem/Chef/Kitchen.h"

using json = nlohmann::json;

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
void floor() {
    std::cout << "Floor" << std::endl;
    Floor* floor = new Floor();
    std::vector<Customer*> customers;
    customers.push_back(new Customer("Neo", 0.5));
    customers.push_back(new Customer("Trinity", 0.5));
    customers.push_back(new Customer("Morpheus", 0.5));
    floor->customerEnter(customers);
    floor->addStaff(new Waiter());
    floor->createTables(5, 4);
    floor->checkTable(0, 0);
    floor->checkTable(0, 0);
}
// out:
//  Floor
//  Table 0 has 3 customers.
//  Not ready to order
//  Not ready to order
//  Not ready to order
//  Table 0 has 3 customers.
//  [Waiting]: Where's the food at???
//  [Eating]: Visited by waiter
//  [Paying]: Give payment to waiter
//  COS 214 - Final Project
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

void askTimePassed(Kitchen* kitchen) {
    int timePassed;
    while (true) {
        std::cout << "Enter time passed (sec): ";
        std::cin >> timePassed;

        kitchen->updateTime(timePassed);
        std::cout << kitchen->toString() << std::endl;
        Meal* meal = kitchen->getOutgoingMeal();
        while (meal != nullptr) {
            std::cout << "Meal ready!" << std::endl;
            std::cout << meal->toString() << std::endl;
            meal = kitchen->getOutgoingMeal();
        }

        // Do something with timePassed
    }
}

void test() {
    Kitchen* kitchen = new Kitchen();
    // Order* o = new Order("bob");
    // Order* b = new Order("alice");
    // kitchen->handleOrder(o);
    // kitchen->handleOrder(b);
    askTimePassed(kitchen);
}

int main() {

    menuTest();
    TerminalApp app;
    app.run();
    return 0;
    floor();
    // TerminalApp app;
    // app.run();
    // return 0;

    // ResourceManager<sf::Texture, FloorView::SpriteType> tableSprites;
    // tableSprites.load(FloorView::SingleTable, "assets/textures/table.png");

    // FloorStaff* staff = new Waiter();
    // Customer customer("Bob", 4);
    // customer.interact(*staff);

    // ResourceManager<sf::Texture> textures;
    // textures.load(0, "assets/hunny.png");

    // ActionMap<PlayerInput> map;
    // map.map(PlayerInput::Up, Action(sf::Keyboard::Up));
    // map.map(PlayerInput::Down, Action(sf::Keyboard::Down));
    // map.map(PlayerInput::Right, Action(sf::Keyboard::Right));
    // map.map(PlayerInput::Left, Action(sf::Keyboard::Left));
    // map.map(PlayerInput::Click, Action(sf::Mouse::Left, Action::Pressed));

    // ActionTarget<PlayerInput> target(map);

    // Player player(target);

    // std::cout << "COS 214 - Final Project" << std::endl;
    // std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;

    // readAssetFile("demo_asset.json");
    // sf::RenderWindow w(sf::VideoMode(1280, 720),
    //     "COS 214 Final Project",
    //     sf::Style::Default ^ sf::Style::Resize);

    // sf::RectangleShape r({300, 200});
    // sf::Sprite sprite(*textures.get(0));

    // // TableView table(tableSprites);
    // // TablePresenter presenter(table, w);
    // // table.position({100, 100});

    // r.setPosition({10, 10});
    // r.setFillColor(sf::Color(255, 0, 0));
    // sf::Clock clock;
    // float lastTime = clock.getElapsedTime().asSeconds();

    // FloorView view(12, 7, tableSprites);
    // view.position({10, 10});
    // view.placeTable(1, 1);
    // view.placeTable(2, 1);
    // view.placeTable(3, 1);

    // while (w.isOpen()) {
    //     // Handle Events
    //     sf::Event e;
    //     while (w.pollEvent(e)) {
    //         // table.onEvent(e);

    //         target.processEvent(e);
    //         if (e.type == sf::Event::EventType::Closed) {
    //             w.close();
    //         }
    //     }

    //     w.clear();
    //     float dt = clock.getElapsedTime().asSeconds() - lastTime;
    //     lastTime += dt;

    //     target.processEvents();
    //     player.update(dt);

    //     w.draw(sprite);

    //     player.draw(w);

    //     target.processEvents();

    //     // Time-based update
    //     float dt = clock.getElapsedTime().asSeconds() - lastTime;
    //     lastTime += dt;

    //     player.update(dt);
    //     // presenter.update(dt);

    //     // Render window
    //     w.clear();

    //     w.draw(sprite);
    //     player.draw(w);
    //     // table.draw(w);
    //     view.draw(w);

    //     w.display();
    //     // rect.draw(w);
    // }
}