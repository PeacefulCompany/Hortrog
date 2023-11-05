#pragma once

class Payment {
public:
    Payment();
    Payment(int tableId, float amount);
    float getAmountOfPayment() const;
    void setAmountOfPayment(float amount);
    float gettableId() const;
    void settableId(int tableId);
    virtual void paymentDetails() const;
private:
    float amountOfPayment;
    int tableId;
};