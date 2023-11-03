#include "Modifier.h"
#include <sstream>

double Modifier::total() {
    double ret = 0;
    ret += component->total();
    ret += price;
    return ret; // test
}

std::string Modifier::toJson() {
    std::stringstream s;
    s << "{\"component\": " << component->toJson();
    s << ", \"modifier\": " << key << "}";
    return s.str();
}
Modifier::Modifier(std::unique_ptr<Order> component) {
    this->component = std::move(component);
}
