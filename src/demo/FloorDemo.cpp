#include "FloorDemo.h"
#include "core/util.h"

#include "customer/Customer.h"
#include "customer/CustomerState.h"
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
#include <string>
#include <vector>

void FloorDemo::gameLoop() {
    // Draw tables
    // std::cout << util::CLEAR_SCREEN << util::HOME << std::endl;
    std::cout << "--- THE FLOOR ---" << std::endl;
    std::cout << floor_.toString() << std::endl;
    std::cout << "---------------------------" << std::endl;

    // Chose next action
    if (mainOptions_.execute()) {
        running_ = false;
    }
}

void FloorDemo::init() {
    menu_.loadFromFile("menu_items.json");

    mainOptions_.addCommand("Add Table", [this]() { addTable(); });
    mainOptions_.addCommand("Add Customers", [this]() { addCustomers(); });
    mainOptions_.addCommand("Add Staff", [this]() { addStaff(); });
    mainOptions_.setPrompt("Choose an option (-1 to quit): ");
    mainOptions_.setExitCode(-1);
}

void FloorDemo::cleanup() {}

void FloorDemo::addTable() {
    int capacity;
    do {
        capacity = util::input("Number of seats: ");
    } while (capacity < 1);

    std::cout << "Table ID: " << floor_.addTable(capacity);
}
void FloorDemo::addCustomers() {
    int numCustomers = util::input("Number of customers: ");
    Table* table = floor_.requestSeating(numCustomers);
    if (!table) {
        util::error("Cannot accomadate that many customers");
        return;
    }
    std::cout << table->toString() << std::endl;

    std::string line;
    for (int i = 0; i < numCustomers; i++) {
        std::cout << "Customer name: ";
        std::getline(std::cin, line);
        Customer* c = new Customer(line, 100);
        table->seatCustomer(c);
    }
}

void FloorDemo::addStaff() {
    CommandMenu menu;
    menu.addCommand(
        "Waiter", [this]() { floor_.addStaff(new Waiter(&menu_)); });
    menu.addCommand("Manager", [this]() { floor_.addStaff(new Manager()); });
    menu.setError("Invalid staff type.");
    menu.setPrompt("Enter staff type: ");

    menu.execute();
}
