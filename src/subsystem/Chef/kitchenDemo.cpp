#include "kitchenDemo.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/KitchenStaff.h"
#include "subsystem/Chef/kitchenDemo.h"
#include <iostream>
#include <string>
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
    menu_->loadFromFile("menu_items.json");
    orderBuilder_ = new ConcreteOrderBuilder(menu_);
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
    std::cout << "=============================" << std::endl;
    std::cout << "Welcome to the Kitchen Demo!" << std::endl;
    std::cout << "Please select an option:" << std::endl;
    std::cout << "1. Simulate time passed" << std::endl;
    std::cout << "2. Display kitchen snapshot" << std::endl;
    std::cout << "3. Display menu" << std::endl;
    std::cout << "4. Display order builder" << std::endl;
    std::cout << "5. Add Chef" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "=============================" << std::endl;
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

void KitchenDemo::displayModifiers() {
    // Modi
}

void KitchenDemo::menuHandler() {
    int choice;
    while (true) {
        displayMainMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: simulateTimePassed(); break;
        case 2: displayKitchenSnapshot(); break;
        case 3: displayMenu(); break;
        case 4: displayOrderBuilderMenu(); break;
        case 5: displayAddChef(); break;
        case 6: return;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}

void KitchenDemo::displayOrderBuilderMenu() {
    int choice;
    orderBuilder_->begin(1);
    while (true) {
        std::cout << "=============================" << std::endl;
        std::cout << "Welcome to the Order Builder!" << std::endl;
        std::cout << "Please select an option:" << std::endl;
        // std::cout << "0. Add Modifier" << std::endl;
        std::cout << "1. Add item to order" << std::endl;
        std::cout << "2. Display order" << std::endl;
        std::cout << "3. Submit order" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "=============================" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;
        switch (choice) {
        // case 0: addOrderBuilderModifier(); break;
        case 1: addOrderBuilderItem(); break;
        case 2: std::cout << orderBuilder_->getResult() << std::endl; break;
        case 3: kitchen_->handleOrder(orderBuilder_->getOrder()); break;
        case 4: return;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}

void KitchenDemo::addOrderBuilderItem() {
        std::cout << "=============================" << std::endl;
    displayMenu();
    std::string key;
    std::string customerName;
    std::string modifierQuery;
    std::cin.ignore();
    std::cout << "Enter item key: \n";
    // std::cin.ignore();
    std::getline(std::cin, key);
    std::cout << "Enter customer name: ";
    std::getline(std::cin, customerName);
    std::cout << "Customer Name: " << customerName << std::endl;
    if (orderBuilder_->addItem(key, customerName)) {
        std::cout << "Item added" << std::endl;
        std::cout << "Do you want to add a modifier? (y/n)" << std::endl;
        std::getline(std::cin, modifierQuery);
        std::cout << modifierQuery << std::endl;
        if (modifierQuery == "y" || modifierQuery == "n") {
            while (modifierQuery != "y" && modifierQuery != "n") {
                std::cout << "Invalid input" << std::endl;
                std::cout << "Do you want to add a modifier? (y/n)"
                          << std::endl;
                std::getline(std::cin, modifierQuery);
            }
        }

        if (modifierQuery == "y") {
            addOrderBuilderModifier();
        } else {
            std::cout << "No modifier added" << std::endl;
        }
    } else {
        std::cout << "Item not added" << std::endl;
    }
        std::cout << "=============================" << std::endl;

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

void KitchenDemo::displayAddChef() {

        std::cout << "=============================" << std::endl;

    std::cout << "Please enter the role of the chef you would like to add: \n";
    std::string role;
    std::cin >> role;

    std::cout
        << "Please enter the rating of the chef you would like to add: \n";
    std::string rating;
    std::cin >> rating;
    try {
        int intRating = std::stoi(rating);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return;
    }

    std::cout
        << "Please enter the capacity of the chef you would like to add: \n";
    std::string capacity;
    std::cin >> capacity;
    try {
        int intCapacity = std::stoi(capacity);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return;
    }

    std::cout << "Please enter the speed of the chef you would like to add: \n";
    std::string speed;
    std::cin >> speed;
    try {
        int intSpeed = std::stoi(speed);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        return;
    }

    KitchenStaff* newChef = new NormalChef(std::stoi(rating),
        std::stoi(capacity),
        this->kitchen_,
        std::stoi(speed),
        role);

    int addMore = 1;

    while (addMore != 0) {
        std::cout << "Would you like to add a dish that this chef can prepare? "
                     "(1 for yes, 0 for no): ";
        std::cin >> addMore;
        if (addMore == 1) {
            std::cout << "Please enter the name of the dish: ";
            std::string dish;
            std::cin >> dish;
            ((NormalChef*)newChef)->addCanPrepareItem(dish);
        }
    }

    kitchen_->AddChef(newChef);
        std::cout << "=============================" << std::endl;

}