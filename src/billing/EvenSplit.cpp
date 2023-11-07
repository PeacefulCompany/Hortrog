#include "EvenSplit.h"
std::vector<Receipt> EvenSplit::getReceipts(std::vector<Order*> orders) {
    int numCustomers = this->countCustomers(orders);
    std::vector<Receipt> returnVector;
    double total = 0;
    for (auto order : orders) {
        total += order->total();
    }
    double amountPerCustomer = total / numCustomers;
    for (int i = 0; i < numCustomers; ++i) {
        Receipt receipt = Receipt();
        receipt.addPair(std::pair<std::string, double>("One part of bill", amountPerCustomer));
        returnVector.push_back(receipt);
    }
    return returnVector;
}
