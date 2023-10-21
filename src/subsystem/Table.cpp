#include "Table.h"
Table::Table(std::string name, double price) : Order(name, price) {}
Table::~Table() {}
void Table::add(Order* order) {
    if (this->order == 0) {
        this->order = order;
    } else {
        this->order->add(order);
    }
};
std::string Table::getJson() {
    if (this->order == 0) {
        return "}";
    } else {
        return "{\n" + getJsonSting() + ",\n" + this->order->getJson();
    }
};
double Table::getCost() { return 0; };
