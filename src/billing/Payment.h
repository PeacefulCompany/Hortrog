#pragma once
#include <iostream>
#include <string>

class Payment {
public:
    Payment();
    Payment(float amount);
    float getAmountOfPayment() const;
    void setAmountOfPayment(float amount);
    virtual void paymentDetails() const;
private:
    float amountOfPayment;
};

class CashPayment : public Payment {
public:
    CashPayment();
    CashPayment(float amount, float cashPaid);
    float getCashPaid() const;
    void setCashPaid(float cashPaid);
    void paymentDetails() const override;
private:
    float cashPaid;
};

class CreditCardPayment : public Payment {
public:
    CreditCardPayment();
    CreditCardPayment(float amount, const std::string& nameOnCard, const std::string& expirationDate, const std::string& creditCardNumber);
    const std::string& getNameOnCard() const;
    const std::string& getExpirationDate() const;
    const std::string& getCreditCardNumber() const;
    void setNameOnCard(const std::string& nameOnCard);
    void setExpirationDate(const std::string& expirationDate);
    void setCreditCardNumber(const std::string& creditCardNumber);
    void paymentDetails() const override;
private:
    std::string nameOnCard;
    std::string expirationDate;
    std::string creditCardNumber;
};