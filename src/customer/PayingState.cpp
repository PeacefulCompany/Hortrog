#include "PayingState.h"
#include <iostream>

void PayingState::visit(Manager& m) {
    std::cout << "[Paying]: Give payment to manager" << std::endl;
    customer_->changeState(nullptr);
}

void PayingState::visit(Waiter& w) {
    std::cout << "[Paying]: Give payment to waiter" << std::endl;
    customer_->changeState(nullptr);
}
