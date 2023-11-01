#include "subsystem/MealItem.h"
#include <chrono>
#include <iostream>
#include <thread>
MealItem::MealItem(std::string customer, std::string food, float quality) {
    customer_ = customer;
    food_ = food;
    quality_ = quality;
}
