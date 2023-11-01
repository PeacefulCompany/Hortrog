#pragma once

#include "Order.h"

class OrderItem : public Order{
private:
    std::string id;
    double price;
public:
    std::string toJson() override;
    double total() override;
};