#ifndef SUBBILL_H
#define SUBBILL_H

#include <vector>
#include <string>
#include "Bill.h"

class SubBill : public Bill {
private:
    std::string description;
    std::vector<Bill*> subBills;
public:
    SubBill(const std::string& description);
    double calculateTotal() override;
    void makePayment(double amount) override;
    void addChild(Bill* bill) override;
    void removeChild(Bill* bill) override;
    std::vector<Bill*> getChildren() override;
    Bill* getChild(int index) override;
};

#endif