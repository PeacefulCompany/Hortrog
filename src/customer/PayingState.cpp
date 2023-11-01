#include "PayingState.h"
#include <iostream>

void PayingState::visit(Manager& m) {
    std::cout << "Paying: Manager" << std::endl;
}

void PayingState::visit(Waiter& w) {
    std::cout << "Paying: Waiter" << std::endl;
}
