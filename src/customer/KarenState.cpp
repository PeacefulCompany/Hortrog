#include "KarenState.h"
#include <iostream>

void KarenState::visit(Manager& m) {
    std::cout << "Karen: Manager" << std::endl;
}

void KarenState::visit(Waiter& w) { std::cout << "Karen: Waiter" << std::endl; }
