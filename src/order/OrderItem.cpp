#include "OrderItem.h"

std::string OrderItem::toJson() {
    std::string ret =  "\"" + id + "\" : ";
    ret += price;
    return ret;
}

double OrderItem::total() {
    return price;
}
