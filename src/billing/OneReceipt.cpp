#include "OneReceipt.h"
std::vector<Receipt> OneReceipt::getReceipts(std::vector<Order*> orders) {
    Receipt bigReceipt;
    for (auto order  : orders) {
        Receipt receipt;
        receipt.generateOrders(order);
        bigReceipt.appendReceipt(&receipt);
    }
    std::vector<Receipt> returnVector;
    returnVector.push_back(bigReceipt);
    return returnVector;
}
