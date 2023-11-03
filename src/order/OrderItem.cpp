#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret = "{\"name\": \"" + id + "\",";
    ret += "\"price\": " + std::to_string(price) + "}";
    return ret;
}

double OrderItem::total() { return price; }
void OrderItem::add(std::unique_ptr<Order>) {}
OrderItem::OrderItem(std::string id, double price) {
    this->id = id;
    this->price = price;
}
void OrderItem::setPrice(double price) { this->price = price; }
double OrderItem::getPrice() const { return this->price; }

std::string OrderItem::getId() { return this->id; }
std::vector<std::pair<std::string, double>>
OrderItem::generateReceiptOrderList() {
    std::vector<std::pair<std::string, double>> returnVec;
    returnVec.emplace_back(id, price);
}
