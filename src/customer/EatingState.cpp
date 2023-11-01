#include "EatingState.h"
#include <iostream>

void EatingState::visit(Manager& m) {
    std::cout << "Eating: Manager" << std::endl;
}

void EatingState::visit(Waiter& w) {
    std::cout << "Eating: Waiter" << std::endl;
}
