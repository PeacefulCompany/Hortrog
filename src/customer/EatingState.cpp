#include "EatingState.h"
#include "customer/Customer.h"
#include "customer/OrderingState.h"
#include "customer/PayingState.h"
#include <iostream>
#include <stdlib.h>

void EatingState::visit(Manager& m) {
    std::cout << "[Eating]: Visited by manager" << std::endl;
}

void EatingState::visit(Waiter& w) {
    std::cout << "[Eating]: Visited by waiter" << std::endl;
    update(1); // to be removed
}
void EatingState::update(float dt) {
    eatTime_.update(dt);
    if (eatTime_.expired()) {
        if (rand() % 2 == 0) {
            std::cout << "[Eating] Done eating, but I want more" << std::endl;
            customer_->changeState(new OrderingState(customer_));
        } else {
            std::cout << "[Eating] Done eating, let me pay" << std::endl;
            customer_->changeState(new PayingState(customer_));
        }
    } else {
        std::cout << "Still eating: "
                  << (eatTime_.duration() - eatTime_.current()) << std::endl;
    }
}
