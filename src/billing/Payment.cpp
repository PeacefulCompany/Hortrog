#include "Payment.h"
#include <iostream>

Payment::Payment() : amountOfPayment(0.0) {}

Payment::Payment(int tableId,float amount) : amountOfPayment(amount) {
    this->tableId=tableId;
}

float Payment::getAmountOfPayment() const {
    return amountOfPayment;
}

void Payment::setAmountOfPayment(float amount) {
    amountOfPayment = amount;
}

float Payment::gettableId() const {
    return tableId;
}

void Payment::settableId(int id) {
    tableId = id;
}

void Payment::paymentDetails() const {
    std::cout << "Payment amount: $" << amountOfPayment << std::endl;
}


