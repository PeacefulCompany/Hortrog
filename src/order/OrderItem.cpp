//ORDERITEMPP
#include "OrderItem.h"
#include "menu/Menu.h"

OrderItem::OrderItem(const MenuItem* item) : item_(item) {}

std::string OrderItem::toJson() {
    std::string ret = "{\"name\": \"" + item_->getName() + "\",";
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
    std::string customerName, std::vector<MenuItem*> menuItems) {
    if (customerName == customer_){
        for (auto& item : menuItems) {
            if (item->getName() == item_->getName()) {
                return true;
            }
        }
    }
    return false;
}
std::vector<MenuItem*> OrderItem::getAllMenuItems() {
    std::vector<MenuItem*> returnVector;
    MenuItem * item = item_;
    returnVector.push_back(&(*item_));
}
