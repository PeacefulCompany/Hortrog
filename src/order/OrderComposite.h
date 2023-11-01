#pragma once

#include <vector>
#include "Order.h"

class OrderComposite : public Order{
private:
    std::vector<std::shared_ptr<Order>> orders;
public:
    void add(std::shared_ptr<Order> order) override;
    std::string toJson() override;
    double total() override;
};