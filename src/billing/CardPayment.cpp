#include "CardPayment.h"
#include <iostream>


CardPayment::CardPayment() : Payment(), cardPaid(0.0), nameOnCard(""), expirationDate(""), creditCardNumber("") {}

CardPayment::CardPayment(Payment* payment, float amount, const string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber) : Payment(payment), cardPaid(amount),nameOnCard(nameOnCard), expirationDate(expirationDate), creditCardNumber(creditCardNumber) {}


const string& CardPayment::getNameOnCard() const { return nameOnCard; }

const string& CardPayment::getExpirationDate() const { return expirationDate; }

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

float CardPayment::getCardPaid() const {
    return cardPaid;
}

void CardPayment::setCardPaid(float cardPaid) {
    this->cardPaid = cardPaid;
}

void CardPayment::paymentDetails() const {
    cout << "Bill amount: $" << getAmountOfPayment() << endl;
    cout << "Payment method: Card" << endl;
    cout << "Name on card: " << getNameOnCard() << endl;
    cout << "Expiration date: " << getExpirationDate() << endl;
    cout << "Credit card number: " << getCreditCardNumber() << endl;
    std::cout << "Amount paid: $" << getCardPaid() << std::endl;
}