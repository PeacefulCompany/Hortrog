#include "Floor.h"
#include "customer/Customer.h"
#include "customer/EatingState.h"
#include "customer/PayingState.h"
#include "customer/WaitingState.h"

#include <iostream>

Floor::Floor() {}
Floor::~Floor() {}
void Floor::createTables(int numTables, int numSeats) {
    for (int i = 0; i < numTables; i++) {
        Table* table = new Table();
        table->id_ = i;
        table->seats_ = numSeats;
        table->waiterId_ = -1;
        tables_.push_back(table);
    }
}
void Floor::addCustomerToTable(Customer* customer, int tableId) {
    if (tableId < static_cast<int>(tables_.size())) {
        tables_[tableId]->addCustomer(customer);
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}
void Floor::addCustomerToTable(std::vector<Customer*> customers) {
    int tableId;
    for (int i = 0; i < static_cast<int>(tables_.size()); i++) {
        if (tables_[i]->customersAtTable_.size() < tables_[i]->seats_) {
            tableId = i;
            break;
        }
    }

    if (tableId < static_cast<int>(tables_.size())) {
        for (int i = 0; i < static_cast<int>(customers.size()); i++) {
            tables_[tableId]->addCustomer(customers[i]);
        }
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}
void Floor::customerEnter(std::vector<Customer*> customers) {
    for (int i = 0; i < static_cast<int>(customers.size()); i++) {
        floorCustomers_.push_back(customers[i]);
    }
}
void Floor::customerEnter(Customer* customer) {
    floorCustomers_.push_back(customer);
}

void Floor::removeCustomerFromTable(Customer* customer, int tableId) {
    if (tableId < static_cast<int>(tables_.size())) {
        for (int i = 0;
             i < static_cast<int>(tables_[tableId]->customersAtTable_.size());
             i++) {
            if (tables_[tableId]->customersAtTable_[i] == customer) {
                tables_[tableId]->customersAtTable_.erase(
                    tables_[tableId]->customersAtTable_.begin() + i);
                return;
            }
        }
        std::cout << "Customer not found at table." << std::endl;
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
}

void Floor::addStaff(FloorStaff* staff) {
    staff_.push_back(staff);
    // if tables nul create table and add waiter to table
    if (tables_.empty()) {
        createTables(1, 4);
    }
    for (int i = 0; i < static_cast<int>(tables_.size()); i++) {
        if (tables_[i]->waiterId_ == -1) {
            tables_[i]->waiterId_ = staff_.size() - 1;
            break;
        }
    }
}

void Floor::removeStaff(FloorStaff* staff) {
    for (int i = 0; i < static_cast<int>(staff_.size()); i++) {
        if (staff_[i] == staff) {
            staff_.erase(staff_.begin() + i);
            return;
        }
    }
    std::cout << "Staff not found." << std::endl;
}

void Floor::checkTable(int tableId) {
    if (tableId < static_cast<int>(tables_.size())) {
        std::cout << "Table " << tableId << " has "
                  << tables_[tableId]->customersAtTable_.size() << " customers."
                  << std::endl;
        for (int i = 0;
             i < static_cast<int>(tables_[tableId]->customersAtTable_.size());
             i++) {
            static_cast<void>(tables_[tableId]->customersAtTable_[i]->interact(
                *staff_[tables_[tableId]->waiterId_]));
        }
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
    // change tables sates to ready to order
    for (int i = 0;
         i < static_cast<int>(tables_[tableId]->customersAtTable_.size());
         i++) {
        if (tables_[i]->customersAtTable_.size() > 0) {
            tables_[i]->customersAtTable_[0]->changeState(
                new WaitingState(tables_[i]->customersAtTable_[tableId]));
            tables_[i]->customersAtTable_[1]->changeState(
                new EatingState(tables_[i]->customersAtTable_[tableId]));
            tables_[i]->customersAtTable_[2]->changeState(
                new PayingState(tables_[i]->customersAtTable_[tableId]));
        }
    }
}
