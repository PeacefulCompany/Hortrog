#pragma once
#include "Order.h"
class Modifier : public Order {
public:
    Modifier(Order* order);
    ~Modifier();
    void add(Order* order);
    virtual double total();

protected:
    Order* Component;
    virtual std::string printOrder();

private:
};