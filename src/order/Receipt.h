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
    void addPair(std::pair<std::string, double> pair){orderList_.push_back(pair);};
    void appendReceipt(Receipt * receipt);
};
