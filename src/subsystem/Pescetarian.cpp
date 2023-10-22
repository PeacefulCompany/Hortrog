#include "Pescetarian.h"
Pescetarian::Pescetarian(std::unique_ptr<Order> order)
    : Modifier(std::move(order)) {
    setCost(this->price);
}
std::string Pescetarian::printOrder() {
    std::string output = "";
    output += Modifier::printOrder();
    output += this->spesification + "\n";
    return output;
}