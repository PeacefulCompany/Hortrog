#pragma once

#include "CustomerState.h"
#include "core/Timer.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
class OrderingState : public CustomerState {
public:
    OrderingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    void update(float dt) override;

    std::string toString() const override;

private:
    Timer readyTimer_ = Timer(1);
};