#include "floor/Floor.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"

#include "customer/Customer.h"
#include "customer/EatingState.h"
#include "customer/PayingState.h"
#include "customer/WaitingState.h"
#include "floor/CustomerIterator.h"
#include "floor/TableGroup.h"
#include "staff/Waiter.h"

#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <utility>
#include <vector>

uint32_t Floor::addTable(int capacity) {
    uint32_t id = tableCount_++;
    tables_.push_back(new TableComponent(id, capacity));
    return id;
}

Table* Floor::requestSeating(int n) {
    using namespace std;

    // Find all empty tables
    vector<Table*> emptyTables;
    auto func = [](const Table* t) { return t->isEmpty(); };
    copy_if(tables_.begin(), tables_.end(), back_inserter(emptyTables), func);

    // Find combination of tables
    int currentCapacity = 0;
    auto it = emptyTables.begin();
    for (; it != emptyTables.end(); it++) {
        if (currentCapacity >= n) break;
        currentCapacity += (*it)->capacity();
    }
    if (currentCapacity < n) return nullptr;
    if (it != emptyTables.end()) {
        emptyTables.erase(it);
    }
    if (emptyTables.size() == 1) {
        return emptyTables[0];
    }

    // Group them together
    TableGroup* group = new TableGroup();
    for (Table* table : emptyTables) {
        group->merge(table);
        erase(tables_, table);
    }
    tables_.push_back(group);

    return group;
}

void Floor::createTables(int numTables, int numSeats) {
    for (int i = 0; i < numTables; i++) {
        tables_.push_back(new TableComponent(i, numSeats));
    }
}
void Floor::addCustomerToTable(Customer* customer, int tableId) {
    if (tableId < static_cast<int>(tables_.size())) {
        tables_[tableId]->seatCustomer(std::move(customer));
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}
void Floor::addCustomerToTable(std::vector<Customer*> customers) {
    int tableId;
    for (int i = 0; i < static_cast<int>(tables_.size()); i++) {
        if (customers.size() < tables_[i]->capacity()) {
            tableId = i;
            break;
        }
    }
    if (tableId < static_cast<int>(tables_.size())) {
        for (int i = 0; i < static_cast<int>(customers.size()); i++) {
            tables_[tableId]->seatCustomer(customers[i]);
        }
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}

void Floor::customerEnter(std::vector<Customer*> customers) {
    for (int i = 0; i < customers.size(); i++) {
        floorCustomers_.push_back(customers[i]);
    }
}
void Floor::customerEnter(Customer* customer) {
    floorCustomers_.push_back(customer);
}
void Floor::removeCustomerFromTable(Customer* customer, int tableId) {
    if (tableId < static_cast<int>(tables_.size())) {
        tables_[tableId]->removeCustomer(customer);
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}

void Floor::addStaff(FloorStaff* staff) { staff_.push_back(staff); }

void Floor::removeStaff(FloorStaff* staff) {
    for (int i = 0; i < static_cast<int>(staff_.size()); i++) {
        if (staff_[i] == staff) {
            staff_.erase(staff_.begin() + i);
            return;
        }
    }
    std::cout << "Staff not found." << std::endl;
}
void Floor::checkAllTables() {
    for (int i = 0; i < tables_.size(); i++) {
        if (tables_[i]->isEmpty()) continue;
        int waiterId = 0;
        for (int j = 0; j < staff_.size(); j++) {
            if (staff_[j]->getStaffType() == "Waiter") {
                Waiter* waiter = dynamic_cast<Waiter*>(staff_[j]);
                for (int k = 0; k < waiter->getTables().size(); k++) {
                    std::vector<Table*> table = waiter->getTables();
                    if (table[k]->id() == tables_[i]->id()) {
                        waiterId = j;
                        break;
                    }
                }
            }
            checkTable(i, waiterId);
        }
    }
}

void Floor::kitchenCall() {
    for (int i = 0; i < staff_.size(); i++) {
        if (staff_[i]->getStaffType() == "Waiter") {
            Waiter* waiter = dynamic_cast<Waiter*>(staff_[i]);
            checkKitchen(waiter);
        }
    }
}
void Floor::checkKitchen(Waiter* waiter) { waiter->checkKitchen(); }
void Floor::checkTable(int tableId, int waiterId) {
    Waiter* tableWaiter = dynamic_cast<Waiter*>(staff_[waiterId]);
    CustomerIterator* iterator = new CustomerIterator(tables_[tableId]);
    std::srand(std::time(nullptr));
    tableWaiter->getOrderBuilder()->begin(tableId);
    while (!iterator->isDone()) {
        iterator->get()->interact(*staff_[waiterId]);
        iterator->next();
    }
    tableWaiter->giveToKitchen();
    delete iterator;
}

void Floor::seatTheFloor() {
    // i want a distrebution rate of 5:3:2 for customer grouping (5:3:2 is the
    // ratio of 1:2:3)
}

std::string Floor::toString() const {
    std::stringstream ss;
    ss << "Tables:";
    for (const auto& table : tables_) {
        std::stringstream ts(table->toString());
        std::string line;
        std::getline(ts, line);
        ss << "\n- " << line;
        while (!ts.eof()) {
            std::getline(ts, line);
            ss << "\n  " << line;
        }
    }
    ss << "\nStaff:";
    for (const auto& staff : staff_) {
        std::stringstream ts(staff->toString());
        std::string line;
        std::getline(ts, line);
        ss << "\n- " << line;
        while (!ts.eof()) {
            std::getline(ts, line);
            ss << "\n  " << line;
        }
    }
    return ss.str();
}

Waiter* Floor::getWaiter(int waiterId) const {
    if (waiterId < 0) return nullptr;
    if (waiterId >= staff_.size()) return nullptr;

    return dynamic_cast<Waiter*>(staff_[waiterId]);
}

FloorStaff* Floor::getFloorStaff(int waiterId) const {
    if (waiterId < 0) return nullptr;
    if (waiterId >= staff_.size()) return nullptr;
    return staff_[waiterId];
}

void Floor::update(float dt) {
    for (Table* t : tables_) {
        t->update(dt);
    }
}
