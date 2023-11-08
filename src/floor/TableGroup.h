#pragma once

#include "floor/Table.h"
#include "floor/TableComponent.h"

class TableGroup : public Table {
public:
    void buildOrder(OrderBuilder& builder) override;

    bool merge(Table* table) override;
    std::vector<TableComponent*> split() override;

    bool seatCustomer(Customer* customer) override;
    bool removeCustomer(Customer* customer) override;

    bool isEmpty() const override;
    int capacity() const override;
    uint32_t id() const override;

    std::string toString() const override;

    void update(float dt) override;

private:
    std::vector<TableComponent*> tables_;
};