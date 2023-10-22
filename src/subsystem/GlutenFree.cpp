#include "GlutenFree.h"
GlutenFree::GlutenFree(Order* order) : Modifier(order) { setCost(this->price); }
std::string GlutenFree::printOrder() {
    std::string output = "";
    output += Modifier::printOrder();
    output += this->spesification + "\n";
    return output;
}