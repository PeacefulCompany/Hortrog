#pragma once

#include <memory>

// #include "OrderJSON.h"
#include "order/Order.h"
#include "subsystem/Meals/Meal.h"
#include "subsystem/Meals/MealItem.h"
#include "subsystem/menu/OrderJSON.h"
#include <iostream>

class Kitchen;

class KitchenStaff {
protected:
    // KitchenStaff* nextStaff;
    std::unique_ptr<KitchenStaff> nextStaff_;
    int rating_;
    int capacity_;
    int speed_;
    Kitchen* kitchen_;
    int lastTime_ = 0;
    virtual void update();

    std::string role_;

public:
    KitchenStaff(/* args */);
    ~KitchenStaff();

    void updateTime(int delta);
    virtual void prepareMeal(Meal* meal);
    virtual std::string toString();
    void notify();

    void setNextStaff(KitchenStaff* next);
    KitchenStaff* getNextStaff();
};

#include "Kitchen.h"