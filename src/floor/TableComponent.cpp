#include "TableComponent.h"

#include <sstream>
#include <stdlib.h>
#include <vector>

void TableComponent::buildOrder(OrderBuilder& builder) {
    for (Customer* c : customers_) {
        builder.begin(id_);
        builder.addItem(c->getName() + "_burger", c->getName());
        if (rand() % 2 == 0) {
            builder.addModifier("bingus");
        } else if (rand() % 3 == 0) {
            builder.addModifier("grilled");
        }
    }
}

bool TableComponent::seatCustomer(Customer* customer) {
    if (customers_.size() >= capacity_) return false;
    customers_.push_back(customer);
    return true;
}

bool TableComponent::removeCustomer(Customer* customer) {
    return std::erase(customers_, customer) > 0;
}

std::string TableComponent::toString() const {
    std::stringstream s;
    s << "TableComponent: id=" << id_ << ", capacity=" << capacity_;
    for (auto& c : customers_) {
        s << "\n- " << c->toString();
    }
    return s.str();
}

void TableComponent::update(float dt) {
    for (Customer* c : customers_) {
        c->update(dt);
    }
}

bool TableComponent::merge(Table* table) { return false; }
std::vector<TableComponent*> TableComponent::split() { return {this}; }

bool TableComponent::isEmpty() const { return customers_.empty(); }
int TableComponent::capacity() const { return capacity_; }
uint32_t TableComponent::id() const { return id_; }

std::vector<Customer*> TableComponent::getCustomers() const {
    return customers_;
}
