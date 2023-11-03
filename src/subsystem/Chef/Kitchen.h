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
    std::unique_ptr<KitchenStaff> headChef;
    std::queue<Meal*> incomingMeals;
    std::vector<Meal*> outGoingMeals;

public:
    Kitchen();
    void handleOrder(Order* order);
    void clearQueue();
    void handleMeal(Meal* meal);
    void printReadyMeals();

    ~Kitchen();

    void notify();
};

#endif