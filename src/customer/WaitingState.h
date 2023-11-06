#pragma once

#include "CustomerState.h"
#include "customer/Customer.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
class WaitingState : public CustomerState {
public:
    WaitingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

private:

    bool isReady_ = true;
};