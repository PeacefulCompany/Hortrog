// ORDERITEMPP
#include "OrderItem.h"
#include "menu/Menu.h"
#include "order/OrderItem.h"
#include <sstream>

OrderItem::OrderItem(const MenuItem* item) : item_(item) {}

std::string OrderItem::toJson() {
    std::string ret = "{\"name\": \"" + item_->getName() + "\",";
    ret += "\"customer\": \"" + customer_ + "\",";
    ret += "\"price\": " + std::to_string(item_->getPrice()) + "}";
    return ret;
}

double OrderItem::total() { return item_->getPrice(); }
void OrderItem::add(std::unique_ptr<Order>) {}

std::string OrderItem::getId() { return item_->getName(); }
std::vector<std::pair<std::string, double>>
OrderItem::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    returnVec.emplace_back(item_->getName(), item_->getPrice());
    return returnVec;
}
bool OrderItem::checkForCustomer(std::string customerName) {
    return customerName == customer_;
}
bool OrderItem::checkForDupe(
    std::string customerName, std::vector<const MenuItem*> menuItems) {
    if (customerName == customer_) {
        for (auto& item : menuItems) {
            if (item->getName() == item_->getName()) {
                return true;
            }
        }
    }
    return false;
}
std::vector<const MenuItem*> OrderItem::getAllMenuItems() {
    std::vector<const MenuItem*> returnVector;
    returnVector.push_back(item_);
    return returnVector;
}

std::string OrderItem::toString() const {
    std::stringstream ss;
    ss << item_->getName() << " R" << item_->getPrice();
    return ss.str();
}
