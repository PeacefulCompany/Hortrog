#include "MealItem.h"

MealItem::MealItem() {
    // Default constructor
}

MealItem::MealItem(std::string customer, int quality, std::string food) {
    // Constructor with parameters
    this->customer = customer;
    this->quality = quality;
    this->food = food;
}

MealItem::~MealItem() {
    // Destructor
}

std::string MealItem::getCustomer() {
    return customer;
}

void MealItem::setCustomer(std::string customer) {
    this->customer = customer;
}

int MealItem::getQuality() {
    return quality;
}

void MealItem::setQuality(int quality) {
    this->quality = quality;
}

std::string MealItem::getFood() {
    return food;
}

void MealItem::setFood(std::string food) {
    this->food = food;
}
