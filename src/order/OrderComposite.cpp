#include "OrderComposite.h"

void OrderComposite::add(std::unique_ptr<Order> order) {
    orders_.push_back(std::move(order));
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    ret += "\"order\": [\n";
    for (auto& order : orders_) {
        ret += order->toJson() + ",\n";
    }
    // Remove trailing comma
    ret.pop_back();
    ret.pop_back();
    ret += "\n]}\n";
    return ret;
}

double OrderComposite::total() {
    double total = 0;
    for (auto& order : orders_) {
        total += order->total();
    }
    return total;
}
std::vector<std::pair<std::string, double>>
OrderComposite::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    for (auto& order : orders_) {
        auto subTreeVec = order->generateReceiptOrderList();
        for (const std::pair<std::string, double>& itemStr : subTreeVec) {
            returnVec.push_back(itemStr);
        }
    }
    return returnVec;
}
