#include "Modifier.h"

void Modifier::add(std::unique_ptr<Order> order) {
    component_ = std::move(order);
}

double Modifier::total() {
    double ret = 0;
    ret += component_->total();
    ret += price_;
    return ret;//test
}

std::string Modifier::toJson() {
    std::string ret = "\"" + key_ + "\" : ";
    ret += price_;
    ret += component_->toJson();
    return ret;
}
Modifier::Modifier(std::unique_ptr<Order> component) {
    this->component_ = std::move(component);
}
