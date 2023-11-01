#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret =  "\"" + id + "\" : ";
    ret += price;
    return ret;
}

double OrderItem::total() {
    return price;
}
void OrderItem::add(std::shared_ptr<Order>) {}
OrderItem::OrderItem(std::string id, double price) {
    this->id = id;
    this->price = price;
}
void OrderItem::setPrice(double price) {
    this->price = price;
}
double OrderItem::getPrice() { return this->price;}
