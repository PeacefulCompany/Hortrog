#include "Order.h"
#include <iomanip>
Order::Order(std::string name, double price) {
    this->name = name;
    this->price = price;
}
Order::~Order() {}
double Order::getCost() { return this->price; }
void Order::setCost(double price) { this->price = price; }
Order::Order() {}
std::string Order::getJsonSting() {
    std::string json;
    json += this->name + ":" +
            std::to_string(this->price)
                .substr(0, std::to_string(this->price).find(".") + 3);
    return json;
}
