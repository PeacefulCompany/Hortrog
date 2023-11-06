#pragma once

#include "CustomerState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include <string>
class PayingState : public CustomerState {
public:
    PayingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    std::string toString() const override;

private:
    std::string paymentStartegies_[3] = {
        "EvenSplit", "PerCustomer", "OneReceipt"};
    bool isReady_ = false;
};