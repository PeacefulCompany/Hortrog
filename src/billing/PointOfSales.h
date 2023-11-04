#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include "order/ConcreteOrderBuilder.h"
#include "Payment.h"
#include "order/Order.h"

class PointOfSales {
public:
    void registerOrder(Order* order);
    void printBill(int tblId);
    void addBill(int tableNumber, const std::string& itemName, double price, const Payment& payment);
    SubBill* getBill(int tableNumber);
    void removeBill(int tableNumber, const std::string& itemName);
private:
    std::vector<Order*> orders;
};