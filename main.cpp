#include <iostream>
#include "PointOfSales.h"
#include "Payment.h"

int main() {
    // Create a new PointOfSales object
    PointOfSales pos;

    // Add a new bill for table 1, item "Pizza", price $10.00
    Payment payment1(5.00);
    pos.addBill(1, "Pizza", 10.00, payment1);

    // Add a new bill for table 2, item "Burger", price $8.00
    Payment payment2(3.00);
    pos.addBill(2, "Burger", 8.00, payment2);

    // Add a new bill for table 1, item "Soda", price $2.00
    Payment payment3(2.00);
    pos.addBill(1, "Soda", 2.00, payment3);

    // Get the bill for table 1 and print the items and prices
    SubBill* bill1 = pos.getBill(1);
    std::cout << "Table 1 Bill:" << std::endl;
    for (auto child : bill1->getChildren()) {
        std::cout << "    " << child->getName() << " - $" << child->getPrice() << std::endl;
    }

    /* Remove the bill for table 2 and print the remaining bills
    pos.removeBill(2, "Burger");
    std::cout << "Remaining Bills:" << std::endl;
    for (auto sb : pos.getBill()) {
        std::cout << "Table " << sb->getTableNumber() << " - Balance: $" << sb->getBalance() << std::endl;
    }*/

    // Make a payment of $3.00 on the bill for table 1 and print the remaining balance
    Payment payment4(3.00);
    bill1->makePayment(payment4);
    std::cout << "Table 1 Balance: $" << bill1->getBalance() << std::endl;

    return 0;
}