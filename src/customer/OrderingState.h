#pragma once

#include "CustomerState.h"
#include "core/Timer.h"

class OrderingState : public CustomerState {
public:
    void visit(Manager&) override;
    void visit(Waiter&) override;

    void update(float dt) override;

private:
    Timer readyTimer_;
};