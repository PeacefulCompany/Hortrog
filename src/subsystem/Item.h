#pragma once
#include "Order.h"

class Item : public Order {
public:
    Item(std::string menuItem, double price);
    void add(Order*);
    std::string printOrder();
    virtual double total();

private:
    std::string menuItem;
    double price;
};