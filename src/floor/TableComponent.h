#pragma once

#include "floor/Customer.h"
#include "floor/Table.h"
#include <vector>

class TableComponent : public Table {
public:
    Table* merge(Table* table) override;
    std::vector<Table*> split() override;
    bool addCustomer(Customer* customer) override;

    bool isEmpty() const override;
    inline int getCapacity() const override;
    inline uint32_t id() const override;

private:
    std::vector<Customer> customers;
    int id_;
    int capacity_;
    int numCustomers_;
};