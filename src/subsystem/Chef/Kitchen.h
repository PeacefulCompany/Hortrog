#pragma once

#ifndef KITCHEN_H
#define KITCHEN_H

#include "../Meals/Meal.h"
#include "../OrderTemplate/Order.h"
#include "HeadChef.h"
#include "KitchenStaff.h"
#include "NormalChef.h"

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Kitchen {
private:
    KitchenStaff* headChef;
    std::queue<Meal*> incomingMeals;
    std::vector<Meal*> outgoingMeals;

public:
    Kitchen();
    void notifyItemReady();
    void flush();
    void handleOrder(Order* order);
    void updateTime(int time);
    Meal* getOutgoingMeal();
    ~Kitchen();

    void notify();
};

#endif