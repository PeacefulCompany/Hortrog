
#include "MenuItem.h"
MenuItem::MenuItem(std::string name, double price) : Order(name, price) {
    this->order = 0;
}
MenuItem::~MenuItem() { delete this->order; }

void MenuItem::add(Order* order) {
    if (this->order == 0) {
        this->order = order;
    } else {
        this->order->add(order);
    }
};
std::string MenuItem::getJson() {
    if (this->order == 0) {
        return getJsonSting() + "\n}";
    } else {
        return getJsonSting() + ",\n" + this->order->getJson();
    }
}
double MenuItem::getCost() { return Order::getCost(); };
