#include "SubBill.h"
#include <iostream>

SubBill::SubBill(int tableNumber, const std::string& itemName, double price)
    : tableNumber(tableNumber), itemName(itemName), price(price), balance(price) {}

void SubBill::add(Bill* bill) {
    children.push_back(bill);
}

const std::vector<Bill*>& SubBill::getChildren() const {
    return children;
}

void SubBill::operation() {
    std::cout << "SubBill operation" << std::endl;
    for (auto child : children) {
        child->operation();
    }
}

const std::string& SubBill::getName() const {
    return itemName;
}

double SubBill::getPrice() const {
    return price;
}

int SubBill::getTableNumber() const {
    return tableNumber;
}

void SubBill::makePayment(const Payment& payment) {
    balance -= payment.getAmountOfPayment();
    if (balance < 0) {
        balance = 0;
    }
}

double SubBill::getBalance() const {
    return balance;
}