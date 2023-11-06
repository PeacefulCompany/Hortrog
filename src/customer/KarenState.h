#pragma once

#include "CustomerState.h"

class KarenState : public CustomerState {
public:
    KarenState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    std::string toString() const override;

private:
    bool isReady_ = false;
};