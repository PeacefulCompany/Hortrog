#pragma once

#include <string>
#include "Payment.h"
class CardPayment : public Payment {
public:
    CardPayment();
    CardPayment(Payment* payment, float amount, const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber);
    const std::string& getNameOnCard() const;
    const std::string& getExpirationDate() const;
    const std::string& getCreditCardNumber() const;
    void setNameOnCard(const std::string& nameOnCard);
    void setExpirationDate(const std::string& expirationDate);
    void setCreditCardNumber(const std::string& creditCardNumber);
    void paymentDetails() const override;
    float getCardPaid() const;
    void setCardPaid(float cardPaid);
private:
    std::string nameOnCard;
    std::string expirationDate;
    std::string creditCardNumber;
    float cardPaid;
};