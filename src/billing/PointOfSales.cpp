#include "PointOfSales.h"

void PointOfSales::addBill(int tableNumber, const std::string& itemName, double price, const Payment& payment) {
    // Find the sub-bill for this item, or create a new one if it doesn't exist
    SubBill* subBill = nullptr;
    for (auto sb : subBills) {
        if (sb->getName() == itemName && sb->getTableNumber() == tableNumber) {
            subBill = sb;
            break;
        }
    }
    if (!subBill) {
        subBill = new SubBill(tableNumber, itemName, price);
        subBills.push_back(subBill);
    }

    // Add the bill to the sub-bill
    Bill* bill = new Payment(price);
    subBill->add(bill);
}

SubBill* PointOfSales::getBill(int tableNumber) {
    for (auto sb : subBills) {
        if (sb->getTableNumber() == tableNumber) {
            return sb;
        }
    }
    return nullptr;
}

void PointOfSales::removeBill(int tableNumber, const std::string& itemName) {
    for (auto it = subBills.begin(); it != subBills.end(); ++it) {
        if ((*it)->getName() == itemName && (*it)->getTableNumber() == tableNumber) {
            delete *it;
            subBills.erase(it);
            break;
        }
    }
}