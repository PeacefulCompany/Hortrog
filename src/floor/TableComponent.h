#pragma once

#include "customer/Customer.h"
#include "floor/Table.h"
#include <vector>

class TableComponent : public Table {
public:
    TableComponent(uint32_t id, int capacity) : id_(id), capacity_(capacity) {}

    void buildOrder(OrderBuilder& builder) override;
    bool merge(Table* table) override;
    std::vector<TableComponent*> split() override;

    bool seatCustomer(Customer* customer) override;
    bool removeCustomer(Customer* customer) override;

    bool isEmpty() const override;
    int capacity() const override;
    uint32_t id() const override;
    std::vector<Customer*> getCustomers() const;

    std::string toString() const override;

    void update(float dt) override;

private:
    friend class CustomerIterator;
    int id_;
    int capacity_;
    std::vector<Customer*> customers_;
};