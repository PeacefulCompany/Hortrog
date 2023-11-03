#pragma once

#include "Order.h"
#include "OrderItem.h"

class Modifier : public Order {
protected:
    std::unique_ptr<OrderItem> component_;
    std::string key_;
    double price_;

public:
    void add(std::unique_ptr<Order>) override {}
    double total() override;
    std::string toJson() override;
    explicit Modifier(std::unique_ptr<Order> component);
};