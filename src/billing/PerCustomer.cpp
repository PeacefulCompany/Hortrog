#include "PerCustomer.h"
#include <map>
#include <set>
std::vector<Receipt> PerCustomer::getReceipts(std::vector<Order*> orders) {
    std::map<std::string, Receipt> map;
    for (auto order : orders) {
        Receipt receipt;
        receipt.generateOrders(order);
        map[order->getCustomer()].appendReceipt(&receipt);
    }
    std::vector<Receipt> returnVector;
    for (auto pair : map) {
        returnVector.push_back(pair.second);
    }
    return returnVector;
}
