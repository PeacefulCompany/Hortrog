#include "OrderComposite.h"

void OrderComposite::add(std::unique_ptr<Order> order) {
    orders_.push_back(std::move(order));
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    for (auto& order: orders_) {
        ret += order->toJson();
        ret += "\n";
    }
    ret += "}\n";
    return ret;
}

double OrderComposite::total() {
    double total = 0;
    for (auto& order : orders_) {
        total += order->total();
    }
    return total;
}