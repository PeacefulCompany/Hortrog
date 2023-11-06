
#include "customer/Customer.h"
#include "demo/FloorDemo.h"
#include "demo/KitchenDemo.h"
#include "floor/Floor.h"
#include "menu/Menu.h"
#include "staff/Waiter.h"
#include "subsystem/Chef/Kitchen.h"

#include <iostream>

void floor() {
    Menu menu;
    menu.loadFromFile("menu_items.json");

    std::cout << "Floor" << std::endl;
    Floor* floor = new Floor();
    std::vector<Customer*> customers;
    customers.push_back(new Customer("Neo", 0.5));
    customers.push_back(new Customer("Trinity", 0.5));
    customers.push_back(new Customer("Morpheus", 0.5));
    floor->customerEnter(customers);
    floor->addStaff(new Waiter(&menu, floor));
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
    menu->loadFromFile("menu_items.json");

    std::cout << menu->toString() << std::endl;
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
    askTimePassed(kitchen);
}

void testImprovedKitchen() {
    KitchenDemo* kitchen = new KitchenDemo();
    kitchen->run();
}

int main() {
    FloorDemo* floorDemo = new FloorDemo();
    floorDemo->run();
    return 0;
}