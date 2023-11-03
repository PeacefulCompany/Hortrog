#include "TerminalApp.h"

#include "floor/CustomerIterator.h"
#include "floor/TableComponent.h"
#include "floor/TableGroup.h"
#include "order/NullOrderBuilder.h"

#include <iostream>

void TerminalApp::init() {
    std::cout << "COS 214 - Final Project" << std::endl;

    tables_.push_back(new TableComponent(0, 2));
    group_ = new TableGroup();
    group_->merge(new TableComponent(1, 1));
    group_->merge(new TableComponent(2, 2));
    group_->merge(new TableComponent(3, 1));
    group_->seatCustomer(new Customer("John", 4));
    group_->seatCustomer(new Customer("Bob", 4));
    group_->seatCustomer(new Customer("Alice", 4));
    group_->seatCustomer(new Customer("Bingus", 4));
    tables_.push_back(group_);
}

void TerminalApp::gameLoop() {
    int opt = 0;
    std::cout << "Enter an option: ";
    std::cin >> opt;
    std::cout << "Option chosen: " << opt << std::endl;
    if (opt == -1) running_ = false;

    for (Table* table : tables_) {
        NullOrderBuilder builder;
        table->buildOrder(builder);

        std::vector<json> order = builder.getResult();
        if (order.size() == 0) {
            std::cout << table->id() << " no order" << std::endl;
            continue;
        }
        for (json o : order) {
            std::cout << o << std::endl;
        }
    }
    CustomerIterator* iterator = group_->createIterator();
    while (!iterator->isDone()) {
        std::cout << iterator->get()->getName() << std::endl;
        iterator->next();
    }
}
