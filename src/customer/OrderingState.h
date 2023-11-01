#pragma once

#include "CustomerState.h"

class OrderingState : public CustomerState {
public:
    void visit(Manager&) override;
    void visit(Waiter&) override;

private:
    bool isReady_ = false;
};