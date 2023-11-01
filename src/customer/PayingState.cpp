#include "PayingState.h"
#include <iostream>

void PayingState::visit(Manager& m) {
    std::cout << "[Paying]: Give payment to manager" << std::endl;
}

void PayingState::visit(Waiter& w) {
    std::cout << "[Paying]: Give payment to waiter" << std::endl;
}
