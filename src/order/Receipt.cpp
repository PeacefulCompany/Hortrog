#include "Receipt.h"
std::vector<std::pair<std::string, double>> Receipt::getOrders() {
    return orderList;
}
void Receipt::generateOrders(Order* order) {
    orderList = order->generateReceiptOrderList();
}
