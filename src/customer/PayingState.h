#pragma once

#include "CustomerState.h"

class PayingState : public CustomerState {
public:
    void visit(Manager&) override;
    void visit(Waiter&) override;

private:
    bool isReady_ = false;
};