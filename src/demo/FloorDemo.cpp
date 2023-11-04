#include "FloorDemo.h"
#include "core/util.h"

#include <iostream>

void FloorDemo::gameLoop() {
    // Draw tables

    // Chose next action
    std::cout << util::options({"Merge table",
                     "Split table",
                     "Add customer",
                     "Remove customer"})
              << std::endl;
    int opt = util::input("Choose an option (-1 to quit): ");

    switch (opt) {
    case -1: {
        running_ = false;
        break;
    }
    case 1: {
        mergeTable();
        break;
    }
    case 2: {
        splitTable();
        break;
    }
    case 3: {
        addCustomer();
        break;
    }
    case 4: {
        removeCustomer();
        break;
    }
    default: {
        std::cout << "Not an option. Try again." << std::endl;
        break;
    }
    }
}

void FloorDemo::init() {
    std::cout << "--- FLOOR DEMO ---" << std::endl;
    return;
}

void FloorDemo::cleanup() {}

void FloorDemo::splitTable() {
    std::cout << "--- TABLE SPLIT ---" << std::endl;
}

void FloorDemo::mergeTable() {
    std::cout << "--- TABLE MERGE ---" << std::endl;
}

void FloorDemo::addCustomer() {
    std::cout << "--- ADD CUSTOMER ---" << std::endl;
}

void FloorDemo::removeCustomer() {
    std::cout << "--- REMOVE CUSTOMER ---" << std::endl;
}
