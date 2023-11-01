#include "WaitingState.h"
#include <iostream>

void WaitingState::visit(Manager& m) {
    std::cout << "Waiting: Manager" << std::endl;
}

void WaitingState::visit(Waiter& w) {
    std::cout << "Waiting: Waiter" << std::endl;
}
