#include "Modifier.h"
Modifier::Modifier(std::unique_ptr<Order> order) {
    this->Component = std::move(order);
}
void Modifier::add(std::unique_ptr<Order> order) {
    this->Component = std::move(order);
}
std::string Modifier::printOrder() { return this->Component->printOrder(); }
double Modifier::total() {
    if (Component == 0) {
        return getCost();
    } else {
        return getCost() + Component->total();
    }
};