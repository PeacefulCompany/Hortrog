#include "MealItem.h"
#include "subsystem/Meals/MealItem.h"
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

bool MealItem::isEqual(MealItem* other) {
    if (this->customer_ != other->customer_) {
        return false;
    }

    if (this->food_ != other->food_) {
        return false;
    }

    if (this->quality_ != other->quality_) {
        return false;
    }

    if (this->diet_ != other->diet_) {
        return false;
    }

    if (this->mod_ != other->mod_) {
        return false;
    }

    return true;
}