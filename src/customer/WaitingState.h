#pragma once

#include "CustomerState.h"
#include "core/Timer.h"
#include "customer/Customer.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
class WaitingState : public CustomerState {
public:
    WaitingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;
    void update(float dt) override;

private:
    bool isReady_ = false;
    Timer waitTimeout_ = Timer(2);
};