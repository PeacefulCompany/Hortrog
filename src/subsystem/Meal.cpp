#include "subsystem/Meal.h"
#include <string>

float Meal::getQuality() {
    float quality = 0;
    for (auto& item : items_) {
        quality += item.getQuality();
    }
    return quality;
}

Order* Meal::getOrder() { return order_.get(); }

std::vector<MealItem> Meal::takeMeal() { return items_; }

bool Meal::isReady() {
    if (items_.size() == order_->getOrders().size()) {
        return true;
    }
    return false;
}

void Meal::addItem(MealItem item) { items_.push_back(item); }

std::string Meal::getJSONOrder() { return order_->toJson(); }

std::string Meal::getCustomer() { return order_->getCustomer(); }
