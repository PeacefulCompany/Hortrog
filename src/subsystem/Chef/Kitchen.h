#pragma once

#include <memory>
#ifndef KITCHEN_H
#define KITCHEN_H

#include "../Meals/Meal.h"
#include "../OrderTemplate/Order.h"
#include "HeadChef.h"
#include "KitchenStaff.h"
#include "NormalChef.h"
#include "../WaiterTemplate/Waiter.h"
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Waiter;
class Kitchen {
private:
    std::vector<Waiter*> waiters_;
    std::unique_ptr<KitchenStaff> headChef;
    std::queue<Meal*> incomingMeals;
    std::vector<Meal*> outgoingMeals;

public:
    Kitchen();
    void notifyItemReady();
    void flush();
    void handleOrder(Order* order);
    void updateTime(int time);
    Meal* getOutgoingMeal();

    void notify();
    std::vector<Meal*> collectOrders();
    void subscribe(Waiter*);
    void unsubscribe(Waiter*);
    Order* getOrder();

    std::string toString();
    ~Kitchen();
};

#endif