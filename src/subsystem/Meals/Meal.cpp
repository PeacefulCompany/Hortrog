#include "Meal.h"
#include <sstream>
#include <string>
#include <vector>

float Meal::getQuality() {
    float quality = 0;
    for (auto& item : items_) {
        quality += item->getQuality();
    }
    return quality;
}

Order* Meal::getOrder() { return order_.get(); }

std::vector<MealItem*>& Meal::takeMeal() { return items_; }

bool Meal::isReady() {
    // if (items_.size() == order_->getOrders().size()) {
    //     return true;
    // }
    return ready_;
}

std::string Meal::toString() {
    std::stringstream ss;
    ss << "Meal(" << getCustomer() << ")";

    for (auto& item : items_) {
        ss << "\n- " << item->toString();
    }
    return ss.str();
}

void Meal::addItem(MealItem* item) { items_.push_back(item); }

std::string Meal::getJSON() { return order_->toJson(); }

std::string Meal::getCustomer() { return order_->getCustomer(); }

std::vector<MealItem*>& Meal::getItems() { return items_; }

bool Meal::containsMealItem(MealItem* item) {
    for (auto& i : items_) {
        if (i->isEqual(item)) {
            return true;
        }
    }
    return false;
}