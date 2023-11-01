#include "OrderingState.h"
#include <iostream>

void OrderingState::visit(Manager& m) {
    std::cout << "Ordering: Manager" << std::endl;
}

void OrderingState::visit(Waiter& w) {
    std::cout << "Ordering: Waiter" << std::endl;
}
