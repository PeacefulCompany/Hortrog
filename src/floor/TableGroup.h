#pragma once

#include "floor/Table.h"
#include "floor/TableComponent.h"

class TableGroup : public Table {
public:
    TableGroup* merge(Table* table) override;
    std::vector<TableComponent*> split() override;
    bool addCustomer(Customer* customer) override;

    bool isEmpty() const override;
    int getCapacity() const override;
    uint32_t id() const override;

    void addTable(TableComponent* table);

    std::string toString() const override;

private:
    std::vector<TableComponent*> tables_;
};