#include <iostream>
#include "Bill.h"
#include "Payment.h"
#include "SubBill.h"

int main() {
    // Create a payment
    Payment* payment1 = new Payment(100.0);

    // Create a sub-bill with two payments
    SubBill* subBill1 = new SubBill("Sub-bill 1");
    subBill1->addChild(new Payment(50.0));
    subBill1->addChild(new Payment(75.0));

    // Create another sub-bill with a payment and the previous sub-bill
    SubBill* subBill2 = new SubBill("Sub-bill 2");
    subBill2->addChild(payment1);
    subBill2->addChild(subBill1);

    // Add the sub-bills to a main bill
    SubBill* mainBill = new SubBill("Main bill");
    mainBill->addChild(subBill2);
    mainBill->addChild(new Payment(25.0));

    // Calculate the total amount due
    double total = mainBill->calculateTotal();
    std::cout << "Total amount due: R" << total << std::endl;

    // Make a payment of R50
    payment1->makePayment(50.0);

    // Calculate the new total amount due
    total = mainBill->calculateTotal();
    std::cout << "Total amount due: R" << total << std::endl;


    return 0;
}