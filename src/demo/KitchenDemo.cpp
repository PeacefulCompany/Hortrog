#include "KitchenDemo.h"
#include "core/util.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/Kitchen.h"
#include "subsystem/Chef/KitchenStaff.h"
#include <iostream>
#include <string>

void KitchenDemo::cleanup() {}

// getters and setters

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
/*
When a user prints result of order, they can't add anything to the order :(
*/

void KitchenDemo::simulateTimePassed() {
    int timePassed;
    std::cout << "Enter time passed (sec): ";
    std::cin >> timePassed;
    if (timePassed <= 0) {
        std::cout << "Invalid input" << std::endl;
        return;
    }
    kitchen_.updateTime(timePassed);
}

void KitchenDemo::displayKitchenSnapshot() {
    std::cout << kitchen_.toString() << std::endl;
}

void KitchenDemo::displayModifiers() {
    // Modi
}

void KitchenDemo::displayOrderBuilderMenu() {
    CommandMenu orderMenu;

    orderMenu.addCommand("Add item", [this]() { addOrderBuilderItem(); });
    orderMenu.addCommand("Submit Order", [this]() { completeOrder(); });

    orderMenu.setPrompt("Enter choice (-1 to go back): ");
    orderMenu.setError("Invalid input");
    orderMenu.setExitCode(-1);

    int choice;
    orderBuilder_.begin(1);
    while (true) {
        if (orderMenu.execute() == -1) return;
    }
}

void KitchenDemo::completeOrder() {
    std::cout << orderBuilder_.toString() << std::endl;
    kitchen_.handleOrder(orderBuilder_.getOrder());
}

void KitchenDemo::addOrderBuilderItem() {
    std::cout << menu_.toString() << std::endl;
    const MenuItem* item = nullptr;
    std::string key;
    do {
        key = util::inputString("Enter item key: ");
        item = menu_.getMenuItem(key);
    } while (!item);

    std::string name = util::inputString("Customer name: ");
    if (!orderBuilder_.addItem(key, name)) {
        std::cout << "Failed to add item" << std::endl;
        return;
    }

    const auto& modifiers = item->supportedModifiers();
    if (modifiers.empty()) return;

    std::string modifierQuery =
        util::inputString("Do you want to add a modifier? (y/n)");
    while (modifierQuery != "y" && modifierQuery != "n") {
        std::cout << "Invalid input" << std::endl;
        modifierQuery =
            util::inputString("Do you want to add a modifier? (y/n)");
    }

    if (modifierQuery != "y") {
        return;
    }

    std::cout << util::options(modifiers) << std::endl;
    int opt = -1;
    do {
        opt = util::input("Choose a modifier: ");
    } while (opt < 1 || opt > modifiers.size());

    if (!orderBuilder_.addModifier(modifiers[opt - 1])) {
        std::cout << "Failed to add modifier" << std::endl;
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
        &kitchen_,
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

    kitchen_.AddChef(newChef);
    std::cout << "=============================" << std::endl;
}

void KitchenDemo::init() {
    commands_.addCommand("Pass some time", [this]() { simulateTimePassed(); });
    commands_.addCommand(
        "Display Kitchen snapshot", [this]() { displayKitchenSnapshot(); });
    commands_.addCommand("Display menu",
        [this]() { std::cout << menu_.toString() << std::endl; });
    commands_.addCommand(
        "Display Order Builder", [this]() { displayOrderBuilderMenu(); });
    commands_.addCommand("Add chef", [this]() { displayAddChef(); });

    commands_.setPrompt("Choose an option (-1 to exit): ");
    commands_.setExitCode(-1);
}

void KitchenDemo::gameLoop() {
    std::cout << "\n--- KITCHEN DEMO ---" << std::endl;
    if (commands_.execute() == -1) {
        setRunning(false);
    }
}

KitchenDemo::KitchenDemo(
    Kitchen& kitchen, ConcreteOrderBuilder& builder, Menu& menu)
    : kitchen_(kitchen), orderBuilder_(builder), menu_(menu) {}
