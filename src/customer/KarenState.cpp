#include "KarenState.h"
#include <iostream>

void KarenState::visit(Manager& m) {
    std::cout << "[Karen]: COMPLAIN" << std::endl;
}

void KarenState::visit(Waiter& w) {
    std::cout << "[Karen]: I want the manager!!!" << std::endl;
}
