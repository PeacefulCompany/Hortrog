#include "GlutenFree.h"
GlutenFree::GlutenFree(std::unique_ptr<Order> order)
    : Modifier(std::move(order)) {
    setCost(this->price);
}
std::string GlutenFree::printOrder() {
    std::string output = "";
    output += Modifier::printOrder();
    output += this->spesification + "\n";
    return output;
}