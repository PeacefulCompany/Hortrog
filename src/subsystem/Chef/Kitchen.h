#pragma once

#ifndef KITCHEN_H
#define KITCHEN_H

#include "KitchenStaff.h"
#include "Meal.h"	
#include "HeadChef.h"
#include "NormalChef.h"
#include "../OrderTemplate/Order.h"

#include <queue>
#include <vector>
#include <iostream>
#include <string>


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