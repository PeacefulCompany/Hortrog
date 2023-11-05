#pragma once
#include "Payment.h"

class CashPayment : public Payment {
public:
    CashPayment();
    CashPayment(int tblId, float amount, float cashPaid);
    float getCashPaid() const;
    void setCashPaid(float cashPaid);
    void paymentDetails() const override;
private:
    float cashPaid;
};