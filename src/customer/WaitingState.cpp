#include "WaitingState.h"
#include "customer/EatingState.h"
#include "customer/KarenState.h"

#include <iostream>
#include <stdlib.h>

void WaitingState::visit(Manager& m) {
    std::cout << "[Waiting/visit]: We're still waiting" << std::endl;
}

void WaitingState::visit(Waiter& w) {
    Meal* meal = w.getCustomerMeal(customer_);
    if (meal) {
        std::cout << "[Waiting]: Thanks for the food!!" << std::endl;
        customer_->changeState(new EatingState(customer_, meal));
    } else {
        std::cout << "[Waiting]: Where's the food at???" << std::endl;
    }
}

void WaitingState::update(float dt) {
    waitTimeout_.update(dt);
    if (waitTimeout_.expired()) {
        std::cout << "[Waiting/update]: I've had enough!!!" << std::endl;
        customer_->changeState(new KarenState(customer_));
    }
}
