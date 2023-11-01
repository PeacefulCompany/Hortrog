#include "Modifier.h"

void Modifier::add(std::unique_ptr<Order> order) {
    component = std::move(order);
}

double Modifier::total() {
    double ret = 0;
    ret += component->total();
    ret += price;
    return ret;//test
}

std::string Modifier::toJson() {
    std::string ret = "\"" + key + "\" : ";
    ret += price;
    ret += component->toJson();
    return ret;
}
Modifier::Modifier(std::unique_ptr<Order> component) {
    this->component = std::move(component);
}
