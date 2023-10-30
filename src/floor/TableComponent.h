#pragma once

#include "floor/Customer.h"
#include "floor/Table.h"
#include <vector>

class TableComponent : public Table {
public:
    TableGroup* merge(Table* table) override;
    std::vector<TableComponent*> split() override;
    bool addCustomer(Customer* customer) override;

    bool isEmpty() const override;
    int getCapacity() const override;
    uint32_t id() const override;

private:
    int id_;
    int capacity_;
    std::vector<Customer*> customers_;
};