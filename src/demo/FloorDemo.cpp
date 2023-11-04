#include "FloorDemo.h"
#include "core/util.h"

#include "floor/Table.h"
#include "floor/TableComponent.h"

#include <iostream>

void FloorDemo::gameLoop() {
    // Draw tables
    std::cout << util::CLEAR_SCREEN << util::HOME << std::endl;
    std::cout << "--- THE FLOOR ---" << std::endl;

    for (auto& table : tables_) {
        std::cout << table->toString() << std::endl;
    }
    std::cout << "---------------------------" << std::endl;

    // Chose next action
    std::cout << util::options({"Add Table",
                     "Merge table",
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
        addTable();
        break;
    }
    case 2: {
        mergeTable();
        break;
    }
    case 3: {
        splitTable();
        break;
    }
    case 4: {
        addCustomer();
        break;
    }
    case 5: {
        removeCustomer();
        break;
    }
    default: {
        std::cout << "Not an option. Try again." << std::endl;
        break;
    }
    }
}

void FloorDemo::init() { return; }

void FloorDemo::cleanup() {}

void FloorDemo::addTable() {
    std::cout << "--- TABLE ADD ---" << std::endl;

    int id = tableCount_++;
    std::cout << "Creating table with id " << id << std::endl;

    int capacity = util::input("Number of seats: ");
    tables_.emplace_back(std::make_unique<TableComponent>(id, capacity));
}

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
