#include "OrderingState.h"
#include "customer/WaitingState.h"
#include <iostream>

void OrderingState::visit(Manager& m) {
    if (readyTimer_.expired()) {
        std::cout << "Ordering: Manager" << std::endl;
    } else {
        std::cout << "Manager visited" << std::endl;
    }
}

void OrderingState::visit(Waiter& w) {
    if (readyTimer_.expired()) {
        std::cout << "Ordering: Waiter" << std::endl;
        customer_->changeState(new WaitingState(customer_));
    } else {
        std::cout << "Not ready to order" << std::endl;
    }
}

void OrderingState::update(float dt) { readyTimer_.update(dt); }
