#pragma once
#include <vector>
#include "order/Order.h"

class PointOfSales {
public:
    void registerOrder(Order* order);
    void printBill(int tblId);
private:
    std::vector<Order*> orders;
};