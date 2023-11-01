#include "WaitingState.h"
#include "customer/EatingState.h"
#include <iostream>
#include <stdlib.h>

void WaitingState::visit(Manager& m) {
    std::cout << "[Waiting]: We're waiting for food, but it's chill"
              << std::endl;
}

void WaitingState::visit(Waiter& w) {
    // TODO: replace this with actual order pinging
    if (rand() % 2 == 0) {
        std::cout << "[Waiting]: Thanks for the food!!" << std::endl;
        customer_->changeState(new EatingState(customer_));
    } else {
        std::cout << "[Waiting]: Where's the food at???" << std::endl;
    }
}
