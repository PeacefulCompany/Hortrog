#include "OrderComposite.h"

void OrderComposite::add(std::unique_ptr<Order> order) {
    orders.push_back(std::move(order));
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    for (auto& order: orders) {
        ret += order->toJson();
        ret += "\n";
    }
    ret += "}\n";
    return ret;
}

double OrderComposite::total() {
    double total = 0;
    for (auto& order : orders) {
        total += order->total();
    }
    return total;
}