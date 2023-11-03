#include "Receipt.h"
std::vector<std::string> Receipt::getOrders() { return orderList; }
void Receipt::generateOrders(Order* order) {
    orderList = order->generateReceiptOrderList();
}
