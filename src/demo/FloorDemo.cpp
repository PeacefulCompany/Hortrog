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

    // Find the table
    int toSplit = util::input("Enter table ID to split: ");
    auto it = findTable(toSplit);
    if (it == tables_.end()) return;
    if ((*it)->split().size() == 1) return;

    // Split table up
    std::vector<TableComponent*> split = (*it)->split();
    std::transform(split.begin(),
        split.end(),
        std::back_inserter(tables_),
        [](TableComponent* t) { return std::unique_ptr<Table>(t); });

    // Remove group from array
    it->reset();
    std::erase(tables_, nullptr);
}

void FloorDemo::mergeTable() {
    std::cout << "--- TABLE MERGE ---" << std::endl;
    int numToMerge = util::input("Number of tables to merge: ");
    std::set<int> merged;
    for (int i = 0; i < numToMerge; i++) {
        merged.insert(util::input("Table ID: "));
    }

    std::vector<Table*> toMerge;
    for (auto& t : tables_) {
        if (merged.contains(t->id())) {
            toMerge.push_back(t.release());
        }
    }
    std::erase(tables_, nullptr);

    std::unique_ptr<TableGroup> group(new TableGroup());
    for (Table* x : toMerge) {
        group->merge(x);
    }
    tables_.emplace_back(std::move(group));
}

void FloorDemo::addCustomer() {
    std::cout << "--- ADD CUSTOMER ---" << std::endl;

    // Find the table
    int id = util::input("Enter table ID: ");
    auto it = findTable(id);
    if (it == tables_.end()) {
        error("Table not found");
        return;
    }

    // Create customer
    std::cout << "Enter customer name: ";
    std::string name;
    std::getline(std::cin, name);
    Customer* customer = new Customer(name, 10);

    // Add customer to table
    if (!(*it)->seatCustomer(customer)) {
        error("Table is at capacity");
        delete customer;
    }
}

void FloorDemo::removeCustomer() {
    std::cout << "--- REMOVE CUSTOMER ---" << std::endl;

    // Find the table
    int id = util::input("Enter table ID: ");
    auto it = findTable(id);
    if (it == tables_.end()) {
        error("Table not found");
        return;
    }

    int customerNumber = util::input("Customer number: ");
    CustomerIterator* customers = (*it)->createIterator();
    for (int i = 0; i < customerNumber; i++) {
        if (customers->isDone()) {
            error("Customer not found");
            delete customers;
            return;
        }
        customers->next();
    }

    // Create customer
    if (!(*it)->removeCustomer(customers->get())) {
        error("Customer not found");
        delete customers;
        return;
    }
}

std::vector<std::unique_ptr<Table>>::iterator FloorDemo::findTable(int id) {
    for (auto it = tables_.begin(); it != tables_.end(); it++) {
        if ((*it)->id() == id) return it;
    }
    return tables_.end();
}

void FloorDemo::error(const std::string& message) {
    std::cout << message << std::endl;
    std::cin.get();
}
