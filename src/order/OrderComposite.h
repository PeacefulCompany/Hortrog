#pragma once

#include "Order.h"
#include <vector>

class OrderComposite : public Order {
protected:
    std::vector<std::pair<std::string, double>>
    generateReceiptOrderList() override;

private:
    std::vector<std::unique_ptr<Order>> orders_;

public:
    void add(std::unique_ptr<Order> order) override;
    std::string toJson() override;
    double total() override;
};