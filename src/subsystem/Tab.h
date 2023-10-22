#pragma once
#include "Order.h"
#include <iostream>
#include <list>
class Tab : public Order {
public:
    Tab(int tableNumber);
    std::string print();
    void addOrder(Order* order);
    void removeOrder(Order* order);
    double getPrice();

private:
    std::list<Order*> orders;
    int tableNumber;
};
