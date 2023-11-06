#include "Payment.h"
#include <iostream>

Payment::Payment() : amountOfPayment(0.0) {}

Payment::Payment(int tableId,float amount) : amountOfPayment(amount) {
    this->tableId=tableId;
}

Payment::Payment(Payment* payment){
    tableId=payment->gettableId();
    amountOfPayment=payment->getAmountOfPayment();
}

float Payment::getAmountOfPayment() const {
    return amountOfPayment;
}

void Payment::setAmountOfPayment(float amount) {
    amountOfPayment = amount;
}

int Payment::gettableId() const {
    return tableId;
}

void Payment::settableId(int id) {
    tableId = id;
}

void Payment::paymentDetails() const {
    std::cout << "Payment amount: $" << amountOfPayment << std::endl;
}


