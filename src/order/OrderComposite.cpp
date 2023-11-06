//ORDERCOMPP
#include "OrderComposite.h"
#include <iostream>

void OrderComposite::add(std::unique_ptr<Order> order) {
    std::string newCustomer = order->getCustomer();
    bool canAdd = checkForDupe(newCustomer, getAllMenuItems());
    if (canAdd){
        orders_.push_back (std::move(order));
    } else {
        std::cout << "You already ordered that!!";
    }
}


std::string OrderComposite::toJson() {
    std::cout << "Function call happening" << std::endl;
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
bool OrderComposite::checkForCustomer(std::string customerName) {
    for (auto& order : orders_) {
        Order* orderPtr = order.get();
        if (orderPtr->checkForCustomer(customerName)){
            return true;
        }
    }
    return false;
}
bool OrderComposite::checkForDupe(
    std::string customerName, std::vector<MenuItem*> menuItems) {
    for (auto& order : orders_) {
        Order* orderPtr = order.get();
        if (orderPtr->checkForDupe(customerName, menuItems)){
            return true;
        }
    }
    return false;
}
std::vector<MenuItem*> OrderComposite::getAllMenuItems() {
    std::vector<MenuItem*> returnVector;
    for (auto& order : orders_) {
        std::vector<MenuItem*> childVector = order->getAllMenuItems();
        for (auto& item : childVector) {
            returnVector.push_back(item);
        }
    }
    return returnVector;
}
