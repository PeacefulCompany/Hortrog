#pragma once
#include <vector>
#include "order/Order.h"
#include "Payment.h"

class PointOfSales {
public:
    void registerOrder(Order* order);
    void printBill(int tblId);
    bool isPaymentSettled(int tblId);
private:
    std::vector<Order*> orders;
    std::vector<Payment*> payments;
};