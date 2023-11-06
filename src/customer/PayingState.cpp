#include "PayingState.h"
#include "customer/Customer.h"
#include "order/Receipt.h"
#include <cstdlib>
#include <iostream>
#include <random>
#include <vector>

void PayingState::visit(Manager& m) {
    std::cout << "[Paying]: Give payment to manager" << std::endl;
    // w.getPointOfSales()->printBill(customer_->getTableId());
    // w.getPointOfSales()->isPaymentSettled(int tblId);
    // w.getPointOfSales()->payBill(int tblId);
    if (customer_->getHappiness() > 50) {
        m.giveRating(5);
    } else {
        m.giveRating(3);
    }
    customer_->changeState(nullptr);
}

void PayingState::visit(Waiter& w) {
    std::cout << "[Paying]: Give payment to waiter" << std::endl;

    // w.getPointOfSales()->printBill(customer_->getTableId());
    // w.getPointOfSales()->isPaymentSettled(int tblId);
    // w.getPointOfSales()->payBill(int tblId);
    // w.tip(Exta Payment);

    std::cout << "Test" << std::endl;
    std::vector<Receipt> receipt =
        w.synthesizeBill(Customer::paymentSelection, customer_->getTableId());
    for (auto& r : receipt) {
        std::cout << r.toString() << std::endl;
    }
    customer_->changeState(nullptr);
}

std::string PayingState::toString() const { return "[Paying]"; }
