#include "GameDemo.h"
#include "core/util.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/Order.h"
#include "subsystem/Chef/Kitchen.h"

void GameDemo::cleanup() {
    kitchenDemo_->cleanup();
    floorDemo_->cleanup();
    delete kitchenDemo_;
    delete floorDemo_;
}

void GameDemo::gameLoop() {
    if (!current_) {
        std::cout << util::CLEAR_SCREEN << util::HOME << std::endl;
        std::cout << "--- COS 214 - Final Project ---" << std::endl;
        if (commands_.execute() == -1) {
            setRunning(false);
        }
    } else {
        current_->gameLoop();
        if (!current_->isRunning()) {
            current_->setRunning(true);
            current_ = nullptr;
        }
    }
}

void GameDemo::init() {
    menu_.loadFromFile("menu_items.json");
    orderBuilder_ = new ConcreteOrderBuilder(&menu_);
    kitchenDemo_ = new KitchenDemo(kitchen_, *orderBuilder_, menu_);
    floorDemo_ = new FloorDemo(floor_, menu_);

    kitchenDemo_->init();
    floorDemo_->init();

    commands_.addCommand("Kitchen", [this]() { current_ = kitchenDemo_; });
    commands_.addCommand("Floor", [this]() { current_ = floorDemo_; });
    commands_.setExitCode(-1);
    commands_.setPrompt("Enter your choice (-1 to quit): ");
    commands_.setError("Invalid input");
}
