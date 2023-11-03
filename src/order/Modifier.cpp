#include "Modifier.h"

void Modifier::add(std::unique_ptr<OrderItem> order) {
    component_ = std::move(order);
}

double Modifier::total() {
    double ret = 0;
    ret += component_->total();
    ret += price_;
    return ret; // test
}

std::string Modifier::toJson() {
    std::string ret = "{\"name\": \"" + component_->getId() + "\",";
    ret += "\"price\": " + std::to_string(component_->getPrice() + price_);
    ret += ",\"mod\": \"" + key_ + "\"}";
    return ret;
}
Modifier::Modifier(std::unique_ptr<OrderItem> component) {
    this->component_ = std::move(component);
}
