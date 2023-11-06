#include "CardPayment.h"
#include <iostream>


CardPayment::CardPayment() : Payment(), cardPaid(0.0), nameOnCard(""), expirationDate(""), creditCardNumber("") {}

CardPayment::CardPayment(Payment* payment, float amount, const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber) : Payment(payment), cardPaid(amount),nameOnCard(nameOnCard), expirationDate(expirationDate), creditCardNumber(creditCardNumber) {}


const std::string& CardPayment::getNameOnCard() const { return nameOnCard; }

const std::string& CardPayment::getExpirationDate() const { return expirationDate; }

const std::string& CardPayment::getCreditCardNumber() const {
    return creditCardNumber;
}

void CardPayment::setNameOnCard(const std::string& nameOnCard) {
    this->nameOnCard = nameOnCard;
}

void CardPayment::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

void CardPayment::setCreditCardNumber(const std::string& creditCardNumber) {
    this->creditCardNumber = creditCardNumber;
}

float CardPayment::getCardPaid() const {
    return cardPaid;
}

void CardPayment::setCardPaid(float cardPaid) {
    this->cardPaid = cardPaid;
}

void CardPayment::paymentDetails() const {
    std::cout << "Bill amount: $" << getAmountOfPayment() << std::endl;
    std::cout << "Payment method: Card" << std::endl;
    std::cout << "Name on card: " << getNameOnCard() << std::endl;
    std::cout << "Expiration date: " << getExpirationDate() << std::endl;
    std::cout << "Credit card number: " << getCreditCardNumber() << std::endl;
    std::cout << "Amount paid: $" << getCardPaid() << std::endl;
}