#include "Tab.h"
Tab::Tab(int tableNumber) { this->tableNumber = tableNumber; }
std::string Tab::printOrder() {
    std::string output = "Table " + std::to_string(tableNumber) + "\n";
    for (Order* order : orders) {
        output += order->printOrder();
    }
    double price = total();
    output +=
        "Total: $" +
        std::to_string(price).substr(0, std::to_string(price).find(".") + 3) +
        "\n";
    return output;
}
void Tab::add(Order* order) { orders.push_back(order); }
void Tab::removeOrder(Order* order) { orders.remove(order); }
double Tab::total() {
    double price = 0;
    for (Order* order : orders) {
        price += order->total();
    }
    return price;
}
