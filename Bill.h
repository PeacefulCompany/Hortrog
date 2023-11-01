#ifndef BILL_H
#define BILL_H
#include <vector>

class Bill {
public:
    virtual double calculateTotal() = 0;
    virtual void makePayment(double amount) = 0;
    virtual void addChild(Bill* bill);
    virtual void removeChild(Bill* bill);
    virtual std::vector<Bill*> getChildren();
    virtual Bill* getChild(int index);
};

#endif