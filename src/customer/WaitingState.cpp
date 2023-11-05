#include "WaitingState.h"
#include "customer/EatingState.h"
#include <iostream>
#include <stdlib.h>
void WaitingState::visit(Manager& m) {
    std::cout << "[Waiting]: We're waiting for food, but it's chill"
              << std::endl;
}
void WaitingState::visit(Waiter& w) {
    if (w.getReadyMeals().size() > 0) {
        w.giveFoodToCustomer(*customer_);
    } else {
        std::cout << "[Waiting]: Where's the food at???" << std::endl;
    }
}
