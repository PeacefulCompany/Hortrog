#include "floor/Floor.h"
#include "floor/Table.h"
#include "floor/TableComponent.h"

#include "customer/Customer.h"
#include "customer/EatingState.h"
#include "customer/PayingState.h"
#include "customer/WaitingState.h"

#include <iostream>
#include <utility>
#include <vector>
Table* Floor::requestSeating(int n) { return nullptr; }

Floor::Floor() {}
Floor::~Floor() {}
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
            tables_[tableId]->seatCustomer(std::move(customers[i]));
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

void Floor::checkTable(int tableId, int waiterId) {
    if (tableId < static_cast<int>(tables_.size())) {
        std::vector<Customer*> customers_ =
            dynamic_cast<TableComponent*>(tables_[tableId])->getCustomers();
        std::cout << "Table " << tableId << customers_.size() << " has "
                  << tables_[tableId]->capacity() << " Seats." << std::endl;
        for (int i = 0; i < static_cast<int>(customers_.size()); i++) {
            customers_[i]->interact(*staff_[waiterId]);
        }
    } else {
        std::cout << "Table does not exist." << std::endl;
    }
    // change tables sates to ready to order
    // for (int i = 0;
    //      i < static_cast<int>(tables_[tableId]->customersAtTable_.size());
    //      i++) {
    //     if (tables_[i]->customersAtTable_.size() > 0) {
    //         tables_[i]->customersAtTable_[0]->changeState(
    //             new WaitingState(tables_[i]->customersAtTable_[tableId]));
    //         tables_[i]->customersAtTable_[1]->changeState(
    //             new EatingState(tables_[i]->customersAtTable_[tableId]));
    //         tables_[i]->customersAtTable_[2]->changeState(
    //             new PayingState(tables_[i]->customersAtTable_[tableId]));
    //     }
    // }
}
