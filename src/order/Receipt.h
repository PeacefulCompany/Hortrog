#pragma once
#include "Order.h"
#include <string>
#include <vector>
class Receipt {
private:
    std::vector<std::pair<std::string, double>> orderList_;

public:
    /**
     * @brief returns the order list member
     * @return a vector of pairs of key and price
     */
    std::vector<std::pair<std::string, double>> getOrders();
    /**
     * @brief generates a vector of pairs of key words and price
     * @param order the order from which the vector is generated
     */
    void generateOrders(Order* order);
};
