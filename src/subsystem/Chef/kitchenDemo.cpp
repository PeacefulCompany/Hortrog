#include "kitchenDemo.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/kitchenDemo.h"
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
    menu_ = new Menu();
}

KitchenDemo::~KitchenDemo() {
    delete kitchen_;
    delete orderBuilder_;
    delete menu_;
}

// getters and setters

Kitchen* KitchenDemo::getKitchen() { return kitchen_; }

void KitchenDemo::setKitchen(Kitchen* kitchen) { kitchen_ = kitchen; }

ConcreteOrderBuilder* KitchenDemo::getOrderBuilder() { return orderBuilder_; }

void KitchenDemo::setOrderBuilder(ConcreteOrderBuilder* orderBuilder) {
    orderBuilder_ = orderBuilder;
}

Menu* KitchenDemo::getMenu() { return menu_; }

void KitchenDemo::setMenu(Menu* menu) { menu_ = menu; }

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

void KitchenDemo::displayMenu() { std::cout << menu_->toString() << std::endl; }

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
    while (true) {
        std::cout << "Welcome to the Order Builder!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Add item to order" << std::endl;
        std::cout << "2. Remove item from order" << std::endl;
        std::cout << "3. Display order" << std::endl;
        std::cout << "4. Submit order" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: orderBuilder_.; break;
        case 2: removeOrderBuilderItem(); break;
        case 3: displayOrderBuilderOrder(); break;
        case 4: submitOrderBuilderOrder(); break;
        case 5: return;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}
