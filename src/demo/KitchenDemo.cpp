#include "KitchenDemo.h"
#include "core/util.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "subsystem/Chef/KitchenStaff.h"
#include <iostream>
#include <string>

void KitchenDemo::cleanup() {
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
    kitchen_->updateTime(timePassed);
}

void KitchenDemo::displayKitchenSnapshot() {
    std::cout << kitchen_->toString() << std::endl;
}

void KitchenDemo::displayMenu() { std::cout << menu_->toString() << std::endl; }

void KitchenDemo::displayModifiers() {
    // Modi
}

void KitchenDemo::displayOrderBuilderMenu() {
    CommandMenu orderMenu;

    orderMenu.addCommand("Add item", [this]() { addOrderBuilderItem(); });
    orderMenu.addCommand("Show order",
        [this]() { std::cout << orderBuilder_->toString() << std::endl; });
    orderMenu.addCommand("Submit Order",
        [this]() { kitchen_->handleOrder(orderBuilder_->getOrder()); });

    orderMenu.setPrompt("Enter choice (-1 to go back): ");
    orderMenu.setError("Invalid input");
    orderMenu.setExitCode(-1);

    int choice;
    orderBuilder_->begin(1);
    while (true) {
        if (orderMenu.execute() == -1) return;
    }
}

void KitchenDemo::addOrderBuilderItem() {
    displayMenu();

    std::string key = util::inputString("Enter key: ");
    std::string customerName = util::inputString("Enter customer name: ");
    if (!orderBuilder_->addItem(key, customerName)) {
        std::cout << "Item not added" << std::endl;
        return;
    }

    std::cout << "Item added" << std::endl;

    std::string modifierQuery =
        util::inputString("Do you want to add a modifier? (y/n)");
    while (modifierQuery != "y" && modifierQuery != "n") {
        std::cout << "Invalid input" << std::endl;
        modifierQuery =
            util::inputString("Do you want to add a modifier? (y/n)");
    }

    if (modifierQuery == "y") {
        addOrderBuilderModifier();
    } else {
        std::cout << "No modifier added" << std::endl;
    }
}

void KitchenDemo::addOrderBuilderModifier() {
    std::string key = util::inputString("Enter modifier key: ");

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
void KitchenDemo::init() {
    kitchen_ = new Kitchen();
    menu_->loadFromFile("menu_items.json");
    orderBuilder_ = new ConcreteOrderBuilder(menu_);

    commands_.addCommand("Pass some time", [this]() { simulateTimePassed(); });
    commands_.addCommand(
        "Display Kitchen snapshot", [this]() { displayKitchenSnapshot(); });
    commands_.addCommand("Display menu", [this]() { displayMenu(); });
    commands_.addCommand(
        "Display Order Builder", [this]() { displayOrderBuilderMenu(); });
    commands_.addCommand("Add chef", [this]() { displayAddChef(); });

    commands_.setPrompt("Choose an option (-1 to exit): ");
    commands_.setExitCode(-1);
}

void KitchenDemo::gameLoop() {
    std::cout << "\n--- KITCHEN DEMO ---" << std::endl;
    if (commands_.execute() == -1) {
        running_ = false;
    }
}
