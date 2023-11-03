#pragma once
#include "Order.h"
#include <string>
#include <vector>
class Receipt {
private:
    std::vector<std::string> orderList;

public:
    std::vector<std::string> getOrders();
    void generateOrders(Order* order);
};
