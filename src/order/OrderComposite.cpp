// ORDERCOMPP
#include "OrderComposite.h"
#include <iostream>
#include <sstream>

void OrderComposite::add(std::unique_ptr<Order> order) {
    std::string newCustomer = order->getCustomer();
    std::vector<const MenuItem*> menuItems = order->getAllMenuItems();
    bool hasDupe = checkForDupe(newCustomer, menuItems);
    if (!hasDupe) {
        orders_.push_back(std::move(order));
    } else {
        std::cout << "You already ordered that!!";
    }
}

std::string OrderComposite::toJson() {
    std::string ret = "{\n";
    ret += "\"order\": [\n";
    for (auto& order : orders_) {

        ret += order->toJson() + ",\n";
    }
    // Remove trailing comma if orders_ wasn't empty
	if (!orders_.empty())
	{
		ret.pop_back();
		ret.pop_back();
	}
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
        if (orderPtr->checkForCustomer(customerName)) {
            return true;
        }
    }
    return false;
}
bool OrderComposite::checkForDupe(
    std::string customerName, std::vector<const MenuItem*> menuItems) {
    for (auto& order : orders_) {
        Order* orderPtr = order.get();
        if (orderPtr->checkForDupe(customerName, menuItems)) {
            return true;
        }
    }
    return false;
}
std::vector<const MenuItem*> OrderComposite::getAllMenuItems() {
    std::vector<const MenuItem*> returnVector;
    for (auto& order : orders_) {
        std::vector<const MenuItem*> childVector = order->getAllMenuItems();
        for (const MenuItem* item : childVector) {
            returnVector.push_back(item);
        }
    }
    return returnVector;
}

std::string OrderComposite::toString() const {
    std::stringstream ss;
    ss << "OrderComposite";
    for (const auto& o : orders_) {
        std::stringstream stream(o->toString());
        std::string line;

        std::getline(stream, line);
        ss << "\n- " << line;
        while (!stream.eof()) {
            std::getline(stream, line);
            ss << "\n  " << line;
        }
    }
    return ss.str();
}

std::vector<Order*> OrderComposite::getChildren() {
    std::vector<Order*> ret;
    for (auto& order : orders_) {
        ret.push_back(order.get());
    }
    return ret;
}

