#pragma once
#ifndef SUBSYSTEM_MEAL_H
#define SUBSYSTEM_MEAL_H

// file includes
#include "MealItem.h";
#include "OrderTemplate/Order.h"
#include "subsystem/OrderTemplate/Order.h"

// library includes
#include <memory>
#include <vector>

class Meal {

private:
    std::unique_ptr<Order> order_ = std::make_unique<Order>();
    std::vector<MealItem> items_;
    bool ready_ = false;

public:
    inline Meal(Order* order) : order_(order) {}
    float getQuality();
    Order* getOrder();
    std::vector<MealItem> takeMeal();
    void addItem(MealItem);
    bool isReady();
    std::string getJSONOrder();
    std::string getCustomer();
};

#endif