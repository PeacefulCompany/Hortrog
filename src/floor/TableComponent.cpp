#include "TableComponent.h"

#include "TableGroup.h"
#include <sstream>
#include <stdlib.h>

void TableComponent::buildOrder(OrderBuilder& builder) {
    for (Customer* c : customers_) {
        builder.newOrder();
        builder.addItem(c->name + "_burger");
        if (rand() % 2 == 0) {
            builder.addModifier("bingus");
        } else if (rand() % 3 == 0) {
            builder.addModifier("grilled");
        }
    }
}

TableGroup* TableComponent::merge(Table* table) {
    TableGroup* group = new TableGroup();
    group->addTable(this);
    for (TableComponent* t : table->split()) {
        group->addTable(t);
    }
    return group;
}

bool TableComponent::addCustomer(Customer* customer) {
    if (customers_.size() >= capacity_) return false;
    customers_.push_back(customer);
    return true;
}

std::vector<TableComponent*> TableComponent::split() { return {this}; }
bool TableComponent::isEmpty() const { return customers_.empty(); }
int TableComponent::getCapacity() const { return capacity_; }
uint32_t TableComponent::id() const { return id_; }

std::string TableComponent::toString() const {
    std::stringstream s;
    s << "Table(id=" << id_ << ", size=" << capacity_ << ") =";
    for (auto& c : customers_) {
        s << " " << c->name;
    }
    return s.str();
}
