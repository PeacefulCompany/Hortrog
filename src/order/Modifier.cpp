#include "Modifier.h"

void Modifier::add(std::shared_ptr<Order> order) {
    component = order;
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
Modifier::Modifier(std::shared_ptr<Order> component) {
    this->component = component;
}
