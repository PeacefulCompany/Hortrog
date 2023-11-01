#include "WaitingState.h"
#include <iostream>

void WaitingState::visit(Manager& m) {
    std::cout << "[Waiting]: We're waiting for food, but it's chill"
              << std::endl;
}

void WaitingState::visit(Waiter& w) {
    std::cout << "[Waiting]: Where's the food at???" << std::endl;
}
