#include "SubBill.h"

SubBill::SubBill(const std::string& description) : description(description) {}

double SubBill::calculateTotal() {
    double total = 0;
    for (auto subBill : subBills) {
        total += subBill->calculateTotal();
    }
    return total;
}

void SubBill::makePayment(double amount) {
    // Update the payment amount for all child bills
    for (auto subBill : subBills) {
        subBill->makePayment(amount);
    }
}

void SubBill::addChild(Bill* bill) {
    subBills.push_back(bill);
}

void SubBill::removeChild(Bill* bill) {
    for (auto it = subBills.begin(); it != subBills.end(); ++it) {
        if (*it == bill) {
            subBills.erase(it);
            break;
        }
    }
}

std::vector<Bill*> SubBill::getChildren() {
    return subBills;
}

Bill* SubBill::getChild(int index) {
    if (index < 0 || index >= subBills.size()) {
        return nullptr;
    }
    return subBills[index];
}