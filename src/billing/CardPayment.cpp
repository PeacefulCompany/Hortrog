#include "CardPayment.h"
#include <iostream>

CardPayment::CardPayment() : Payment(), nameOnCard(""), expirationDate(""), creditCardNumber("") {}

CardPayment::CardPayment(Payment* payment, const string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber) : Payment(payment), nameOnCard(nameOnCard), expirationDate(expirationDate), creditCardNumber(creditCardNumber) {}

const string& CardPayment::getNameOnCard() const {
    return nameOnCard;
}

const string& CardPayment::getExpirationDate() const {
    return expirationDate;
}

const string& CardPayment::getCreditCardNumber() const {
    return creditCardNumber;
}

void CardPayment::setNameOnCard(const string& nameOnCard) {
    this->nameOnCard = nameOnCard;
}

void CardPayment::setExpirationDate(const string& expirationDate) {
    this->expirationDate = expirationDate;
}

void CardPayment::setCreditCardNumber(const string& creditCardNumber) {
    this->creditCardNumber = creditCardNumber;
}

void CardPayment::paymentDetails() const {
    cout << "Payment amount: $" << getAmountOfPayment() << endl;
    cout << "Payment method: Card" << endl;
    cout << "Name on card: " << getNameOnCard() << endl;
    cout << "Expiration date: " << getExpirationDate() << endl;
    cout << "Credit card number: " << getCreditCardNumber() << endl;
}