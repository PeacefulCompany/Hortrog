#pragma once

#include "CustomerState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
class KarenState : public CustomerState {
public:
    KarenState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

private:
    bool isReady_ = false;
};