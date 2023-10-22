#pragma once
#include "Order.h"
#include <iostream>
#include <list>
class Tab : public Order {
public:
    Tab(int tableNumber);
    std::string printOrder();
    void add(Order* order);
    double total();
    void removeOrder(Order* order);

private:
    std::list<Order*> orders;
    int tableNumber;
};
