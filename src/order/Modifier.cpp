//MODPP
#include "Modifier.h"

double Modifier::total() {
    double ret = 0;
    ret += component_->total();
    ret += price_;
    return ret; // test
}

std::string Modifier::toJson() {
    std::string ret = "{\"name\": \"" + component_->getId() + "\",";
    ret += "\"price\": " + std::to_string(component_->total() + price_);
    ret += ",\"mod\": \"" + key_ + "\"}";
    return ret;
}
Modifier::Modifier(std::unique_ptr<Order> component) {
    this->component_ = std::move(component);
    this->price_ = 0;
}
Modifier::Modifier(std::unique_ptr<Order> component, std::string key) {
    this->component_ = std::move(component);
    this->price_ = 0;
}
std::vector<std::pair<std::string, double>>
Modifier::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    returnVec.emplace_back(key_, price_);
    return returnVec;
}
bool Modifier::checkForDupe(
    std::string customerName, std::vector<MenuItem*> menuItems) {
    return component_->checkForDupe(customerName, menuItems);
}
bool Modifier::checkForCustomer(std::string customerName) {
    return component_->checkForCustomer(customerName);
}