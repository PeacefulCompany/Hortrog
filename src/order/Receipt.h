#pragma once
#include "Order.h"
#include <string>
#include <vector>
class Receipt {
private:
    std::vector<std::pair<std::string, double>> orderList_;

public:
    std::vector<std::pair<std::string, double>> getOrders();
    void generateOrders(Order* order);
};
