
#include "TableGroup.h"
#include "floor/Table.h"

#include "floor/TableComponent.h"
#include "floor/TableGroup.h"

TableGroup* TableGroup::merge(Table* table) {
    TableGroup* group = new TableGroup();
    for (TableComponent* table : table->split()) {
        group->tables_.push_back(table);
    }
    return group;
}

bool TableGroup::addCustomer(Customer* customer) {
    for (TableComponent* table : tables_) {
        if (table->addCustomer(customer)) return true;
    }
    return false;
}

bool TableGroup::isEmpty() const {
    for (TableComponent* table : tables_) {
        if (!table->isEmpty()) return false;
    }
    return true;
}

int TableGroup::getCapacity() const {
    int total = 0;
    for (TableComponent* table : tables_) {
        total += table->getCapacity();
    }
    return total;
}

inline std::vector<TableComponent*> TableGroup::split() { return tables_; }
inline uint32_t TableGroup::id() const { return tables_[0]->id(); }
void TableGroup::addTable(TableComponent* table) { tables_.push_back(table); }
