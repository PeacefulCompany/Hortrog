#include "OrderComposite.h"

void OrderComposite::add(std::unique_ptr<Order> order) {
    orders.push_back(std::move(order));
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    ret += "\"order\": [\n";
    for (auto& order : orders) {
        ret += order->toJson() + ",\n";
    }
    // Remove trailing comma
    ret.pop_back();
    ret += "]\n";
    ret += "}";
    return ret;
}

double OrderComposite::total() {
    double total = 0;
    for (auto& order : orders) {
        total += order->total();
    }
    return total;
}
std::vector<std::string> OrderComposite::generateReceiptOrderList() {
    std::vector<std::string> returnVec;
    for (auto& order : orders) {
        auto subTreeVec = order->generateReceiptOrderList();
        for (const std::string& itemStr : subTreeVec) {
            returnVec.push_back(itemStr);
        }
    }
    return returnVec;
}
