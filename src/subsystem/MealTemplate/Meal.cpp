#include "Meal.h"

// Constructors and Destructors
Meal::Meal() {
    ready = false;
}
Meal::Meal(std::unique_ptr<Order> order) : order(std::move(order)) {}
Meal::~Meal() {}

// Functions
void Meal::addItem(MealItem* item) {
    items.push_back(*item);
}

// Getters and Setters
std::vector<MealItem> Meal::getItems() {
    return items;
}
void Meal::setItems(std::vector<MealItem> items) {
    this->items = items;
}
bool Meal::getReady() {
    return ready;
}
void Meal::setReady(bool ready) {
    this->ready = ready;
}
std::unique_ptr<Order> Meal::getOrder() {
    return std::move(order);
}
void Meal::setOrder(std::unique_ptr<Order> order) {
    this->order = std::move(order);
}
