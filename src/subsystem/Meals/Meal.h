#pragma once
#ifndef SUBSYSTEM_MEAL_H
#define SUBSYSTEM_MEAL_H

// file includes
#include "MealItem.h";
#include "subsystem/OrderTemplate/Order.h"

// library includes
#include <memory>
#include <vector>

class Meal {

private:
    std::unique_ptr<Order> order_ = std::make_unique<Order>();
    std::vector<MealItem*> items_;
    bool ready_ = false;

public:
    inline Meal(Order* order) : order_(order) {}
    float getQuality();
    Order* getOrder();
    std::vector<MealItem*>* takeMeal();
    void addItem(MealItem*);
    bool isReady();
    std::string getJSON();
    std::string getCustomer();
    std::string toString();
    std::vector<MealItem*>* getItems();
    inline bool getReady() { return ready_; }
    inline void setReady(bool rStatus_) { ready_ = rStatus_; }
};

#endif