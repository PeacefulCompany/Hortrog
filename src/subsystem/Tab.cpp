#include "Tab.h"
Tab::Tab(int tableNumber) { this->tableNumber = tableNumber; }
std::string Tab::print() {
    std::string output = "Table " + std::to_string(tableNumber) + "\n";
    for (Order* order : orders) {
        output += order->printOrder();
    }
    output += "Total: $" + std::to_string(getPrice()) + "\n";
    return output;
}
void Tab::addOrder(Order* order) { orders.push_back(order); }
void Tab::removeOrder(Order* order) { orders.remove(order); }
double Tab::getPrice() {
    double price = 0;
    for (Order* order : orders) {
        price += order->total();
    }
    return price;
}
