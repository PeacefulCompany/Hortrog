#include "Modifier.h"

void Modifier::add(std::unique_ptr<OrderItem> order) {
    component = std::move(order);
}

double Modifier::total() {
    double ret = 0;
    ret += component->total();
    ret += price;
    return ret;//test
}

std::string Modifier::toJson() {
    std::string ret =  "{\"name\": \"" + component->getId() + "\",";
	ret += "\"price\": " + std::to_string(component->getPrice()+price);
	ret += ",\"mod\": \"" + key + "\"}";
    return ret;
}
Modifier::Modifier(std::unique_ptr<OrderItem> component) {
    this->component = std::move(component);
}
