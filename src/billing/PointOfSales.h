#pragma once
#include "POSStrategy.h"
#include "Payment.h"
#include "order/Order.h"
#include "order/Receipt.h"
#include <iostream>
#include <vector>

class PointOfSales {
public:
    //    void registerOrder(Order* order);
    //    void printBill(int tblId);
    //    bool isPaymentSettled(int tblId);
    //    //the following 2 functions makes a payment and returns whether the
    //    bill is settled or not bool makeCashPayment(int tblId, float amount);
    //    bool makeCardPayment(int tblId, float amount,const std::string&
    //    nameOnCard, const std::string& expirationDate, const std::string&
    //    creditCardNumber);

    void addOrder(Order* order) {
        std::cout << "Adding order" << std::endl;
        orders_.push_back(order);
    };
    std::vector<Receipt> getReceipt(POSStrategy* strategy, uint32_t tableId);

private:
    std::vector<Order*> orders_;
    std::vector<Payment*> payments_;
    std::unique_ptr<POSStrategy> strategy_;
};