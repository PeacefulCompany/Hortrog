#include "Waiter.h"
#include <iostream>

Waiter::Waiter::Waiter(Kitchen* K) { kitchen_ = K; }

void Waiter::Waiter::checkKitchen() {
    std::cout << "Waiter has collected an order" << std::endl;
}
