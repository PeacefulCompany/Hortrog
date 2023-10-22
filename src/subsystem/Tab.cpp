#include "Tab.h"
Tab::Tab(int tableNumber) { this->tableNumber = tableNumber; }
std::string Tab::printOrder() {
    std::string output = "Table " + std::to_string(tableNumber) + "\n";
    for (const auto& order : orders) {
        output += order->printOrder();
    }
    double price = total();
    output +=
        "Total: $" +
        std::to_string(price).substr(0, std::to_string(price).find(".") + 3) +
        "\n";
    return output;
}
void Tab::add(std::unique_ptr<Order> order) {
    orders.push_back(std::move(order));
}
void Tab::removeOrder(std::unique_ptr<Order> order) { orders.remove(order); }
double Tab::total() {
    double price = 0;
    for (const auto& order : orders) {
        price += order->total();
    }
    return price;
}
