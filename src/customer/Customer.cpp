#include "Customer.h"

#include "customer/OrderingState.h"
#include "staff/FloorStaff.h"

#include <iostream>

Customer::Customer(const std::string& name, float happiness)
    : state_(new OrderingState()), name_(name), happiness_(happiness) {}

void Customer::buildOrder(OrderBuilder& builder) {
    std::cout << "Wot ze fock" << std::endl;
}

void Customer::interact(FloorStaff& staff) { staff.accept(*state_); }

void Customer::update(float dt) { state_->update(dt); }
