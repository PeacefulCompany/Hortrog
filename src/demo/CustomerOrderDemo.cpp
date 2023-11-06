#include "CustomerOrderDemo.h"

void CustomerOrderDemo::init() {
    auto demoCustomer = std::make_unique<Customer>("Stefan", 0.5);
    Menu * menu = new Menu();
    bool noProblems = menu->loadFromFile("../../../assets/menu_items.json");
    printf("Menu Loaded?:%i", noProblems);
}
