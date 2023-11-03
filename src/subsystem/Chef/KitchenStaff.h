#pragma once

#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

// #include "OrderJSON.h"
#include "../Meals/Meal.h"
#include "../Meals/MealItem.h"
#include "../OrderTemplate/Order.h"
#include "../menu/OrderJSON.h"
#include <iostream>

class Kitchen;

class KitchenStaff
{
protected:
    KitchenStaff* nextStaff_;
    int rating;
    int capacity;
    int speed;
    Kitchen* kitchen;
    int lastTime = 0;
    virtual void update();

public:
    KitchenStaff(/* args */);
    ~KitchenStaff();

    void updateTime(int delta);
    virtual void prepareMeal(Meal* meal);
    void notify();

    inline void setNextStaff(KitchenStaff* next){ this->nextStaff_ = next; };
};

#include "Kitchen.h"

#endif // !KITCHENSTAFF_H