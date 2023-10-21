#pragma once
#include "Order.h"
class Table : public Order {
public:
    double getCost();
    std::string getJson();
    void add(Order* order);
    Table(std::string name, double price);
    ~Table();

private:
    Order* order;
};
