#include "Waiter.h"
#include "staff/Waiter.h"
Waiter::Waiter() {}
void Waiter::checkKitchen() {
    std::cout << "kitchen check for orders..." << std::endl;
    // kitchen_->checkForOrders();
}
OrderBuilder* Waiter::getOrderBuilder() {
    std::cout << "Get Generated Order..." << std::endl;
    // orderBuilder_.buildOrder();
    // return orderBuilder_.get();
    return NULL;
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }