#pragma once

#include "CustomerState.h"

class PayingState : public CustomerState {
public:
    PayingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    std::string toString() const override;

private:
    bool isReady_ = false;
};