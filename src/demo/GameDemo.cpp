#include "GameDemo.h"
#include "subsystem/Chef/Kitchen.h"

GameDemo::GameDemo() {
    kitchenDemo_ = new KitchenDemo();
    floorDemo_ = new FloorDemo();
    kitchen_ = new Kitchen();
}

GameDemo::~GameDemo() {
    delete kitchenDemo_;
    delete floorDemo_;
    delete kitchen_;
}

void GameDemo::gameLoop() {
    while (running_) {
        std::cout << "Welcome to the restaurant simulator!" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1. Kitchen" << std::endl;
        std::cout << "2. Floor" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;
        switch (choice) {
        case 1: kitchenDemo_->gameLoop(); break;
        case 2: floorDemo_->gameLoop(); break;
        case 3: running_ = false; break;
        default: std::cout << "Invalid input" << std::endl; break;
        }
    }
}

void GameDemo::init() {
    this->menu_->loadFromFile("menu_items.json");
    this->kitchen_ = new Kitchen();
    


    kitchenDemo_->init();
    floorDemo_->init();
}
