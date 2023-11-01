#include "subsystem/Meal.h"

float Meal::getQuality() {
    float quality = 0;
    for (auto& item : items_) {
        quality += item.getQuality();
    }
    return quality;
}

Order* Meal::getOrder() { return order_.get(); }

std::vector<MealItem> Meal::takeMeal() { return items_; }

bool Meal::isReady() { return ready_; }

void Meal::addItem(MealItem item) { items_.push_back(item); }