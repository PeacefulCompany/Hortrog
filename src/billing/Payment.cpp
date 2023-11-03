#include "Payment.h"

Payment::Payment() : amountOfPayment(0) {}

Payment::Payment(float amount) : amountOfPayment(amount) {}

float Payment::getAmountOfPayment() const {
    return amountOfPayment;
}

void Payment::setAmountOfPayment(float amount) {
    amountOfPayment = amount;
}

void Payment::paymentDetails() const {
    std::cout << "Amount of payment: $" << amountOfPayment << std::endl;
}

CashPayment::CashPayment() : Payment(), cashPaid(0) {}

CashPayment::CashPayment(float amount, float cashPaid) : Payment(amount), cashPaid(cashPaid) {}

float CashPayment::getCashPaid() const {
    return cashPaid;
}

void CashPayment::setCashPaid(float cashPaid) {
    this->cashPaid = cashPaid;
}

void CashPayment::paymentDetails() const {
    std::cout << "Amount of payment: $" << getAmountOfPayment() << std::endl;
    std::cout << "Cash paid: $" << cashPaid << std::endl;
}

CreditCardPayment::CreditCardPayment() : Payment(), nameOnCard(""), expirationDate(""), creditCardNumber("") {}

CreditCardPayment::CreditCardPayment(float amount, const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber)
    : Payment(amount), nameOnCard(nameOnCard), expirationDate(expirationDate), creditCardNumber(creditCardNumber) {}

const std::string& CreditCardPayment::getNameOnCard() const {
    return nameOnCard;
}

const std::string& CreditCardPayment::getExpirationDate() const {
    return expirationDate;
}

const std::string& CreditCardPayment::getCreditCardNumber() const {
    return creditCardNumber;
}

void CreditCardPayment::setNameOnCard(const std::string& nameOnCard) {
    this->nameOnCard = nameOnCard;
}

void CreditCardPayment::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

void CreditCardPayment::setCreditCardNumber(const std::string& creditCardNumber) {
    this->creditCardNumber = creditCardNumber;
}

void CreditCardPayment::paymentDetails() const {
    std::cout << "Amount of payment: $" << getAmountOfPayment() << std::endl;
    std::cout << "Name on card: " << nameOnCard << std::endl;
    std::cout << "Expiration date: " << expirationDate << std::endl;
    std::cout << "Credit card number: " << creditCardNumber << std::endl;
}