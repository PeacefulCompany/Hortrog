#include "Receipt.h"
std::vector<std::pair<std::string, double>> Receipt::getOrders() {
    return orderList_;
}
void Receipt::generateOrders(Order* order) {
    orderList_ = order->generateReceiptOrderList();
}
