#include "Waiter.h"
#include "staff/FloorStaff.h"
#include "staff/Waiter.h"
Waiter::Waiter() : FloorStaff() {}
void Waiter::checkKitchen() {
    std::cout << "kitchen check for orders..." << std::endl;
    // currentmealObjectPointerArray_ = kitchen_->checkForOrders();
    //  add meals
    currentmealObjectPointerArray_.push_back(new std::string("fish"));
    currentmealObjectPointerArray_.push_back(new std::string("chips"));
    currentmealObjectPointerArray_.push_back(new std::string("peas"));
}
OrderBuilder* Waiter::getOrderBuilder() {
    std::cout << "Get Generated Order..." << std::endl;
    // orderBuilder_.buildOrder();
    // return orderBuilder_.get();
    return NULL;
}
void Waiter::accept(CustomerState& state) { state.visit(*this); }