#include "MealItem.h"
#include <chrono>
#include <iostream>
#include <thread>
MealItem::MealItem(std::string customer, float quality, std::string food) {
    customer_ = customer;
    food_ = food;
    quality_ = quality;
}