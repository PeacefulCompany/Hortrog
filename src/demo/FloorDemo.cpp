#include "FloorDemo.h"
#include "core/util.h"

#include "customer/Customer.h"
#include "floor/CustomerIterator.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"

#include <algorithm>
#include <errno.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <vector>

void FloorDemo::gameLoop() {
    // Draw tables
    // std::cout << util::CLEAR_SCREEN << util::HOME << std::endl;
    std::cout << "--- THE FLOOR ---" << std::endl;
    std::cout << floor_.toString() << std::endl;
    std::cout << "---------------------------" << std::endl;

    // Chose next action
    std::cout << util::options({"Add Table"}) << std::endl;
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
    default: {
        std::cout << "Not an option. Try again." << std::endl;
        break;
    }
    }
}

void FloorDemo::init() { return; }

void FloorDemo::cleanup() {}

void FloorDemo::addTable() {
    int capacity;
    do {
        capacity = util::input("Number of seats: ");
    } while (capacity < 1);

    std::cout << "Table ID: " << floor_.addTable(capacity);
}