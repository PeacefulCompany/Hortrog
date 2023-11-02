#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret =  "{\"name\": \"" + id + "\",";
	ret += "\"price\": " + std::to_string(price)+"}";
    return ret;
}

double OrderItem::total() {
    return price;
}
void OrderItem::add(std::unique_ptr<Order>) {}
OrderItem::OrderItem(std::string id, double price) {
    this->id = id;
    this->price = price;
}
void OrderItem::setPrice(double price) {
    this->price = price;
}
double OrderItem::getPrice() { return this->price;}
