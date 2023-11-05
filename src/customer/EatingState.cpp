#include "EatingState.h"
#include "customer/Customer.h"
#include "customer/OrderingState.h"
#include "customer/PayingState.h"
#include <iostream>
#include <stdlib.h>

void EatingState::visit(Manager& m) {
    std::cout << "[Eating/visit]: Visited by manager" << std::endl;
}

void EatingState::visit(Waiter& w) {
    std::cout << "[Eating/visit]: Visited by waiter" << std::endl;
}
void EatingState::update(float dt) {
    eatTime_.update(dt);
    if (!eatTime_.expired()) {
        std::cout << "[Eating/update] Still eating: "
                  << (eatTime_.duration() - eatTime_.current()) << std::endl;
        return;
    }

    if (rand() % 2 == 0) {
        std::cout << "[Eating] What's cookin? Gimme more food" << std::endl;
        customer_->changeState(new OrderingState(customer_));
    } else {
        std::cout << "[Eating/update] I'm stuffed! Lemme pay" << std::endl;
        customer_->changeState(new PayingState(customer_));
    }
}
