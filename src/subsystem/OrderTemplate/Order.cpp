#include "Order.h"

Order::Order(std::string customer) { this->customer = customer; }

Order::Order() { this->customer = ""; }

Order::~Order() {}

void Order::add(Order* order) { std::cout << "adding Order" << std::endl; }

std::string Order::toJson() { return "to json"; }

double Order::total() { return 0.0; }

std::string Order::getCustomer() const { return customer; }

void Order::setCustomer(std::string customer) { this->customer = customer; }

// Path: src/subsystem/OrderTemplate/Order.cpp