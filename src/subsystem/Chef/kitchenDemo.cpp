#include "kitchenDemo.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/kitchenDemo.h"
#include <iostream>
// #include "kitchenDemo.h"

// void test() {
//     Kitchen* kitchen = new Kitchen();
//     Order* o = new Order("bob");
//     Order* b = new Order("alice");
//     kitchen->handleOrder(o);
//     kitchen->handleOrder(b);
//     askTimePassed(kitchen);
// }

// void askTimePassed(Kitchen* kitchen) {
//     int timePassed;
//     while (true) {
//         std::cout << "Enter time passed (sec): ";
//         std::cin >> timePassed;
//         if (timePassed <= 0) {
//             continue;
//         }
//         kitchen->updateTime(timePassed);
//         std::cout << kitchen->toString() << std::endl;
//         Meal* meal = kitchen->getOutgoingMeal();
//         while (meal != nullptr) {
//             std::cout << "Meal ready!" << std::endl;
//             std::cout << meal->toString() << std::endl;
//             meal = kitchen->getOutgoingMeal();
//         }

//         // Do something with timePassed
//     }
// }

// constructor and destructor

KitchenDemo::KitchenDemo() {
    kitchen_ = new Kitchen();
    orderBuilder_ = new ConcreteOrderBuilder();
}

KitchenDemo::~KitchenDemo() {
    delete kitchen_;
    delete orderBuilder_;
}

// getters and setters

Kitchen* KitchenDemo::getKitchen() { return kitchen_; }

void KitchenDemo::setKitchen(Kitchen* kitchen) { kitchen_ = kitchen; }

ConcreteOrderBuilder* KitchenDemo::getOrderBuilder() { return orderBuilder_; }

void KitchenDemo::setOrderBuilder(ConcreteOrderBuilder* orderBuilder) {
    orderBuilder_ = orderBuilder;
}

// other functions

void KitchenDemo::test() {
    // Kitchen* kitchen = new Kitchen();
    // Order* o = new Order("bob");
    // Order* b = new Order("alice");
    // kitchen->handleOrder(o);
    // kitchen->handleOrder(b);
    // askTimePassed(kitchen);
}

void KitchenDemo::askTimePassed(Kitchen* kitchen) {
    int timePassed;
    while (true) {
        std::cout << "Enter time passed (sec): ";
        std::cin >> timePassed;
        if (timePassed <= 0) {
            continue;
        }
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

void KitchenDemo::displayMainMenu() {
    std::cout << "Welcome to the Kitchen Demo!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Simulate time passed" << std::endl;
    std::cout << "2. Display kitchen snapshot" << std::endl;
    std::cout << "3. Display menu" << std::endl;
    std::cout << "4. Display order builder" << std::endl;
    std::cout << "5. Exit" << std::endl;
}

void KitchenDemo::simulateTimePassed() {
    int timePassed;
    std::cout << "Enter time passed (sec): ";
    std::cin >> timePassed;
    if (timePassed <= 0) {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    kitchen_->updateTime(timePassed);
}

void KitchenDemo::displayKitchenSnapshot() {
    std::cout << kitchen_->toString() << std::endl;
}

void KitchenDemo::displayMenu() {
    Menu* menu = orderBuilder_->getMenu();
    menu->initMenu();
    std::cout << menu->toString() << std::endl;
}

void KitchenDemo::menuHandler() {
    int choice;
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        switch (choice) {
        case 1: simulateTimePassed(); break;
        case 2: displayKitchenSnapshot(); break;
        case 3: displayMenu(); break;
        case 4: displayOrderBuilderMenu(); break;
        case 5: return;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}

void KitchenDemo::displayOrderBuilderMenu() {
    int choice;
    orderBuilder_->begin(1);
    while (true) {
        std::cout << "Welcome to the Order Builder!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "0. Add Modifier" << std::endl;
        std::cout << "1. Add item to order" << std::endl;
        std::cout << "2. Display order" << std::endl;
        std::cout << "3. Submit order" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 0: addOrderBuilderModifier(); break;
        case 1: addOrderBuilderItem(); break;
        case 2:
            std::cout << orderBuilder_->getOrder()->toJson() << std::endl;
            break;
        case 3: kitchen_->handleOrder(orderBuilder_->getOrder()); break;
        case 4: return;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}

void KitchenDemo::addOrderBuilderItem() {
    displayMenu();
    std::string key;
    std::string customerName;
    std::cout << "Enter item key: \n";
    std::getline(std::cin, key);
    std::cout << "Enter customer name: ";
    std::cin >> customerName;
    if (orderBuilder_->addItem(key, customerName)) {
        std::cout << "Item added" << std::endl;
    } else {
        std::cout << "Item not added" << std::endl;
    }
}

void KitchenDemo::addOrderBuilderModifier() {
    displayMenu();
    std::string key;
    std::cout << "Enter modifier key: \n";
    std::getline(std::cin, key);

    if (orderBuilder_->addModifier(key)) {
        std::cout << "Modifier added" << std::endl;
    } else {
        std::cout << "Modifier not added" << std::endl;
    }
}
