#include "Waiter.h"
#include "staff/Waiter.h"
Waiter::Waiter() {}
void Waiter::checkKitcken() { cout << "kitchen check for orders..." << endl; }
OrderBuilder* Waiter::getOrderBuilder() {
    cout << "Get Generated Order..." << endl;
    return NULL; // null orderBuilder_.get(); }
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }