#include "Pescetarian.h"
Pescetarian::Pescetarian(Order* order) : Modifier(order) {
    setCost(this->price);
}
std::string Pescetarian::printOrder() {
    std::string output = "";
    output += Modifier::printOrder();
    output += this->spesification + "\n";
    return output;
}