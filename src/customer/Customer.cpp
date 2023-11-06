#include "Customer.h"

#include "customer/CustomerState.h"
#include "customer/EatingState.h"
#include "customer/OrderingState.h"
#include "menu/Menu.h"
#include "order/OrderBuilder.h"
#include "staff/FloorStaff.h"
#include <iostream>
#include <random>
#include <sstream>

int Customer::paymentSelection = 0;

Customer::Customer(const std::string& name, float happiness)
    : state_(new OrderingState(this)), name_(name), happiness_(happiness) {
    initializePaymentSelection();
}

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

std::string Customer::toString() const {
    std::stringstream ss;
    ss << name_ << " (" << happiness_ << ") ";
    if (state_) {
        ss << state_->toString();
    } else {
        ss << "No state";
    }
    return ss.str();
}

void Customer::receiveMeal(Meal* meal) {
    std::cout << "[Customer/receiveMeal] " << name_ << " received meal"
              << std::endl;
    receivedMeal = meal;
}
