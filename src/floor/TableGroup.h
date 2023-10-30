#pragma once

#include "floor/Table.h"
#include "floor/TableComponent.h"

class TableGroup : public Table {
public:
    Table* merge(Table* table) override;
    std::vector<Table*> split() override;
    bool addCustomer(Customer* customer) override;

    bool isEmpty() const override;
    inline int getCapacity() const override;
    inline uint32_t id() const override;

private:
    std::vector<TableComponent*> tables_;
};