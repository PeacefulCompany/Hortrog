#include "Payment.h"
#include <iostream>

Payment::Payment() : amountOfPayment(0.0) {}

Payment::Payment(float amount) : amountOfPayment(amount) {}

float Payment::getAmountOfPayment() const {
    return amountOfPayment;
}

void Payment::setAmountOfPayment(float amount) {
    amountOfPayment = amount;
}

void Payment::paymentDetails() const {
    std::cout << "Payment amount: $" << amountOfPayment << std::endl;
}