#include "CashPayment.h"
#include <iostream>

CashPayment::CashPayment() : Payment(), cashPaid(0.0) {}

CashPayment::CashPayment(float amount, float cashPaid) : Payment(amount), cashPaid(cashPaid) {}

float CashPayment::getCashPaid() const {
    return cashPaid;
}

void CashPayment::setCashPaid(float cashPaid) {
    this->cashPaid = cashPaid;
}

void CashPayment::paymentDetails() const {
    std::cout << "Payment amount: $" << getAmountOfPayment() << std::endl;
    std::cout << "Payment method: Cash" << std::endl;
    std::cout << "Cash paid: $" << getCashPaid() << std::endl;
}