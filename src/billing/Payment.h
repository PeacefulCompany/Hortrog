#pragma once

class Payment {
public:
    Payment();
    Payment(Payment* payment);
    Payment(int tableId, float amount);
    float getAmountOfPayment() const;
    void setAmountOfPayment(float amount);
    int gettableId() const;
    void settableId(int tableId);
    virtual void paymentDetails() const;
private:
    float amountOfPayment;
    int tableId;
};