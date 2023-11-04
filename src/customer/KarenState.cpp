#include "KarenState.h"
#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include <iostream>

void KarenState::visit(Manager& m) {
    std::cout << "[Karen]: COMPLAIN" << std::endl;
    m.lodgeComplaint("Karen is complaining");
    customer_->changeState(nullptr);
}
void KarenState::visit(Waiter& w) {
    std::cout << "[Karen]: I want the manager!!!" << std::endl;
    // w.callManager(); ???
}
