#include "MealItem.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>
MealItem::MealItem(std::string customer, float quality, std::string food, std::string diet ,std::string mod) {
    customer_ = customer;
    food_ = food;
    quality_ = quality;
    diet_ = diet;
    mod_ = mod;
}