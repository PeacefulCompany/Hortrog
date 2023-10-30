#pragma once

#include <vector>

#include "Customer.h"
#include "order/OrderBuilder.h"

class TableComponent;
class TableGroup;

class Table {
public:
    virtual void buildOrder(OrderBuilder& builder) = 0;
    virtual bool addCustomer(Customer* customer) = 0;
    virtual TableGroup* merge(Table* table) = 0;
    virtual std::vector<TableComponent*> split() = 0;

    virtual bool isEmpty() const = 0;
    virtual int getCapacity() const = 0;
    virtual uint32_t id() const = 0;

    virtual std::string toString() const = 0;

private:
};