#include "CashPayment.h"
#include "billing/Payment.h"
#include <iostream>

CashPayment::CashPayment() : Payment(), cashPaid(0.0) {}

CashPayment::CashPayment(Payment* payment, float cashPaid) : Payment(payment), cashPaid(cashPaid) {}

float CashPayment::getCashPaid() const {
    return cashPaid;
}

void CashPayment::setCashPaid(float cashPaid) {
    this->cashPaid = cashPaid;
}

void CashPayment::paymentDetails() const {
    std::cout << "Bill amount: $" << getAmountOfPayment() << std::endl;
    std::cout << "Payment method: Cash" << std::endl;
    std::cout << "Amount paid: $" << getCashPaid() << std::endl;
}