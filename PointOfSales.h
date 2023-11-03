#pragma once
#include <vector>
#include <string>
#include "SubBill.h"
#include "Payment.h"

class PointOfSales {
public:
    void addBill(int tableNumber, const std::string& itemName, double price, const Payment& payment);
    SubBill* getBill(int tableNumber);
    void removeBill(int tableNumber, const std::string& itemName);
private:
    std::vector<SubBill*> subBills;
};