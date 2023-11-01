#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret =  "\"" + id_ + "\" : ";
    ret += price_;
    return ret;
}

double OrderItem::total() {
    return price_;
}
void OrderItem::add(std::unique_ptr<Order>) {}
OrderItem::OrderItem(std::string id, double price) {
    this->id_ = id;
    this->price_ = price;
}
void OrderItem::setPrice(double price) {
    this->price_ = price;
}
double OrderItem::getPrice() { return this->price_;}
