#include "GameDemo.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/Order.h"
#include "subsystem/Chef/Kitchen.h"

void GameDemo::cleanup() {
    delete kitchenDemo_;
    delete floorDemo_;
}

void GameDemo::gameLoop() {
    if (commands_.execute() == -1) running_ = false;
}

void GameDemo::init() {
    menu_.loadFromFile("menu_items.json");
    orderBuilder_ = new ConcreteOrderBuilder(&menu_);
    kitchenDemo_ = new KitchenDemo(kitchen_, *orderBuilder_, menu_);
    floorDemo_ = new FloorDemo(floor_, menu_);

    kitchenDemo_->init();
    floorDemo_->init();

    commands_.addCommand("Kitchen", [this]() { kitchenDemo_->gameLoop(); });
    commands_.addCommand("Floor", [this]() { floorDemo_->gameLoop(); });
    commands_.setExitCode(-1);
    commands_.setPrompt("Enter your choice: ");
    commands_.setError("Invalid input");
}
