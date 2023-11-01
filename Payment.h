#ifndef PAYMENT_H
#define PAYMENT_H

#include "Bill.h"

class Payment : public Bill {
private:
    double amount;
public:
    Payment(double amount);
    double calculateTotal() override;
    void makePayment(double amount) override;
};

#endif