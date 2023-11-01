#include "OrderComposite.h"

void OrderComposite::add(std::shared_ptr<Order> order) {
    orders.push_back(order);
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    for (std::shared_ptr<Order> order : orders) {
        ret += order->toJson();
        ret += "\n";
    }
    ret += "}\n";
    return ret;
}

double OrderComposite::total() {
    double total = 0;
    for (std::shared_ptr<Order> order : orders) {
        total += order->total();
    }
    return total;
}
