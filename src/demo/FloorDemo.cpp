#include "FloorDemo.h"
#include "core/util.h"

#include "floor/Table.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"

#include <algorithm>
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
}

void FloorDemo::removeCustomer() {
    std::cout << "--- REMOVE CUSTOMER ---" << std::endl;
}
