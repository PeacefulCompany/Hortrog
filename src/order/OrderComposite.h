#pragma once

#include "Order.h"
#include <vector>


class OrderComposite : public Order {
public:
    void add(std::unique_ptr<Order> order) override;
    std::string toJson() override;
    double total() override;

private:
    std::vector<std::unique_ptr<Order>> orders;
};