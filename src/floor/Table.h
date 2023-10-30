#pragma once

#include <vector>

#include "Customer.h"

class Table {
public:
    virtual bool addCustomer(Customer* customer) = 0;
    virtual Table* merge(Table* table) = 0;
    virtual std::vector<Table*> split() = 0;

    virtual bool isEmpty() const = 0;
    virtual int getCapacity() const = 0;
    virtual uint32_t id() const = 0;

private:
};