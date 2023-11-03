#include "Waiter.h"
#include <iostream>

Waiter::Waiter::Waiter(Kitchen* K) { kitchen_ = K; }

void Waiter::Waiter::checkKitchen() { meals_ = kitchen_->collectOrders(); }
