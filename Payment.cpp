#include "Payment.h"

Payment::Payment(double amount) : amount(amount) {}

double Payment::calculateTotal() {
    return amount;
}

void Payment::makePayment(double amount) {
    // Update the payment amount
    this->amount -= amount;
    if (this->amount < 0) {
        this->amount = 0;
    }
}