#pragma once

#include "CustomerState.h"
#include "core/Timer.h"

class EatingState : public CustomerState {
public:
    EatingState(Customer* c) : CustomerState(c) {}
    void visit(Manager&) override;
    void visit(Waiter&) override;

    void update(float dt) override;

    std::string toString() const override;

private:
    Timer eatTime_ = Timer(2);
};