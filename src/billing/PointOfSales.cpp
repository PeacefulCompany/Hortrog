#include "PointOfSales.h"
#include "order/Receipt.h"
#include <iostream>

void PointOfSales::registerOrder(Order* order){
    orders.push_back(order);
}


void PointOfSales::printBill(int tblId) {
    std::cout << "========================================" << std::endl;
    std::cout << "            BILL" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Order items:" << std::endl;
    float total=0;
    Receipt* rec=new Receipt();
    std::vector<std::pair<std::string, double>> items;
    for (const auto& order : orders) {
        if(order->getTblId()==tblId){
            rec->generateOrders(order);
            items=rec->getOrders();
            for (const auto& item : items) {
                total+=item.second;
                std::cout << "- " << item.first << ": R" << item.second << std::endl;
            }
        }
    }
    Payment* payment=new Payment(tblId,total);
    payments.push_back(payment);
    std::cout << "Total: R" << total << std::endl;
    std::cout << "========================================" << std::endl;
}

bool PointOfSales::isPaymentSettled(int tblId){
    for (const auto& payment : payments) {
        if(payment->gettableId()==tblId){
            if(payment->getAmountOfPayment()>0){
                return false;
            }
        }
    }
    return true;
}

