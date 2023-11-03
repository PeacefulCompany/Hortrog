#include "KarenState.h"
#include "customer/Customer.h"
#include <iostream>

void KarenState::visit(Manager& m) {
    std::cout << "[Karen]: COMPLAIN" << std::endl;
    customer_->changeState(nullptr);
}

void KarenState::visit(Waiter& w) {
    std::cout << "[Karen]: I want the manager!!!" << std::endl;
}
