#include "bill.h"

const std::string& Bill::getName() const {
    static std::string empty;
    return empty;
}

double Bill::getPrice() const {
    return 0.0;
}

void Bill::add(Bill* bill) {
    // Do nothing
}

const std::vector<Bill*>& Bill::getChildren() const {
    static std::vector<Bill*> empty;
    return empty;
}

void Bill::operation() {
    // Do nothing
}