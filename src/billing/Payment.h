#pragma once

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