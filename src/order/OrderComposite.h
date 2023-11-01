#pragma once

#include <vector>
#include "Order.h"

class OrderComposite : public Order{
private:
    std::vector<std::unique_ptr<Order>> orders;
public:
    void add(std::unique_ptr<Order> order) override;
    std::string toJson() override;
    double total() override;
};