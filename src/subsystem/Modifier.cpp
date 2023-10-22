#include "Modifier.h"
Modifier::Modifier(Order* order) { this->Component = order; }
void Modifier::add(Order* order) { this->Component = order; }
Modifier::~Modifier() { delete this->Component; }
std::string Modifier::printOrder() { return this->Component->printOrder(); }
double Modifier::total() {
    if (Component == 0) {
        return getCost();
    } else {
        return getCost() + Component->total();
    }
};