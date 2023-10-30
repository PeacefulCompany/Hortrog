#include "TableComponent.h"

#include "TableGroup.h"

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

inline std::vector<TableComponent*> TableComponent::split() { return {this}; }
inline bool TableComponent::isEmpty() const { return customers_.empty(); }
inline int TableComponent::getCapacity() const { return capacity_; }
inline uint32_t TableComponent::id() const { return id_; }