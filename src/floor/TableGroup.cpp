
#include "TableGroup.h"
#include "floor/Table.h"

#include "floor/TableComponent.h"
#include "floor/TableGroup.h"
#include <sstream>
#include <string>

void TableGroup::buildOrder(OrderBuilder& builder) {
    for (TableComponent* table : tables_) {
        table->buildOrder(builder);
    }
}

bool TableGroup::merge(Table* table) {
    for (TableComponent* c : table->split()) {
        tables_.push_back(c);
    }
    return true;
}

bool TableGroup::seatCustomer(Customer* customer) {
    for (TableComponent* table : tables_) {
        if (table->seatCustomer(customer)) {
            customer->setTableID(id());
            return true;
        }
    }
    return false;
}

bool TableGroup::removeCustomer(Customer* customer) {
    for (TableComponent* table : tables_) {
        if (table->removeCustomer(customer)) return true;
    }
    return false;
}

bool TableGroup::isEmpty() const {
    for (TableComponent* table : tables_) {
        if (!table->isEmpty()) return false;
    }
    return true;
}

int TableGroup::capacity() const {
    int total = 0;
    for (TableComponent* table : tables_) {
        total += table->capacity();
    }
    return total;
}

std::vector<TableComponent*> TableGroup::split() { return tables_; }
uint32_t TableGroup::id() const { return tables_[0]->id(); }

std::string TableGroup::toString() const {
    std::stringstream s;
    s << "TableGroup: id=" << id() << ", capacity=" << capacity();
    for (TableComponent* table : tables_) {
        s << "\n - " << table->toString();
    }
    return s.str();
}

void TableGroup::update(float dt) {
    for (TableComponent* table : tables_) {
        table->update(dt);
    }
}
