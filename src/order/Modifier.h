#pragma once

#include "Order.h"
#include "OrderItem.h"

class Modifier : public Order{
protected:
    std::unique_ptr<OrderItem> component;
    std::string key;
    double price;
public:
    void add(std::unique_ptr<OrderItem>);
    double total() override;
    std::string toJson() override;
    explicit Modifier(std::unique_ptr<OrderItem> component);
};