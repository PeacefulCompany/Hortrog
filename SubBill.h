#pragma once
#include <vector>
#include <string>
#include "Bill.h"
#include "Payment.h"

class SubBill : public Bill {
public:
    SubBill(int tableNumber, const std::string& itemName, double price);
    void add(Bill* bill) override;
    const std::vector<Bill*>& getChildren() const override;
    void operation() override;
    const std::string& getName() const override;
    double getPrice() const override;
    int getTableNumber() const;
    void makePayment(const Payment& payment);
    double getBalance() const;
private:
    int tableNumber;
    std::string itemName;
    double price;
    std::vector<Bill*> children;
    double balance;
};