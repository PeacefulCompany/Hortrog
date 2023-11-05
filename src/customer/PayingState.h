#pragma once

#include "CustomerState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
class PayingState : public CustomerState {
public:
    PayingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

private:
    bool isReady_ = false;
};