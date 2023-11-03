#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret = "{\"name\": \"" + id_ + "\",";
    ret += "\"price\": " + std::to_string(price_) + "}";
    return ret;
}

double OrderItem::total() { return price_; }
void OrderItem::add(std::unique_ptr<Order>) {}
OrderItem::OrderItem(std::string id, double price) {
    this->id_ = id;
    this->price_ = price;
}
void OrderItem::setPrice(double price) { this->price_ = price; }
double OrderItem::getPrice() { return this->price_; }

std::string OrderItem::getId() { return this->id_; }
std::vector<std::pair<std::string, double>>
OrderItem::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    returnVec.emplace_back(id_, price_);
}
