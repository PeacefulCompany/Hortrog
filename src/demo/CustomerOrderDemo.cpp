#include "CustomerOrderDemo.h"
#include "order/ConcreteOrderBuilder.h"
#include "staff/Waiter.h"

#include <memory>

void CustomerOrderDemo::init() {
    auto stefan = std::make_unique<Customer>("Stefan", 0.5);
    auto linda = std::make_unique<Customer>("Linda", 0.8);
    Menu * menu = new Menu();
    bool isLoaded = menu->loadFromFile("menu_items.json");
    if (!isLoaded){
        std::vector<std::string> mods;
        mods.emplace_back("Vegan");
        mods.emplace_back("Vegetarian");
        menu->addMenuItem("borger", std::make_unique<MenuItem>("borger", 2.0, "Grill", mods));
        std::vector<std::string> mods2;
        mods2.emplace_back("Pescatarian");
        mods2.emplace_back("Fresh");
        menu->addMenuItem("hortdog", std::make_unique<MenuItem>("hortdog", 3.2, "Fried", mods2));
    }
    auto orderBuilder = std::make_unique<ConcreteOrderBuilder>(menu);
    Waiter waiter;

}
