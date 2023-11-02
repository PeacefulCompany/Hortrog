#include "Waiter.h"
#include "staff/Waiter.h"
Waiter::Waiter() {}
void Waiter::checkKitchen() {
    cout << "kitchen check for orders..." << endl;
    // kitchen_->checkForOrders();
}
OrderBuilder* Waiter::getOrderBuilder() {
    cout << "Get Generated Order..." << endl;
    // orderBuilder_.buildOrder();
    // return orderBuilder_.get();
    return NULL;
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }