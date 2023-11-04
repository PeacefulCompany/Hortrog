#include "Customer.h"

#include "Menu/Menu.h"
#include "Order/OrderBuilder.h"
#include "customer/CustomerState.h"
#include "customer/OrderingState.h"
#include "staff/FloorStaff.h"
#include <iostream>

Customer::Customer(const std::string& name, float happiness)
    : state_(new OrderingState(this)), name_(name), happiness_(happiness) {}

void Customer::interact(FloorStaff& staff) {
    if (!state_) {
        std::cout << "[Customer/interact] no state" << std::endl;
        return;
    }
    staff.accept(*state_);
}

void Customer::update(float dt) {
    if (!state_) {
        std::cout << "[Customer/update] no state" << std::endl;
        return;
    }
    state_->update(dt);
}

void Customer::changeState(CustomerState* state) { state_.reset(state); }
