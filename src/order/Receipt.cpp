#include "Receipt.h"
std::vector<std::pair<std::string, double>> Receipt::getOrders() {
    return orderList_;
}
void Receipt::generateOrders(Order* order) {
    orderList_ = order->generateReceiptOrderList();
}
void Receipt::appendReceipt(Receipt* receipt) {
    for (auto pair : receipt->getOrders()) {
        orderList_.push_back(pair);
    }
}


