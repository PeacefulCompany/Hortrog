#pragma once

#include "subsystem/Meals/Meal.h"
#include <memory>

#include "HeadChef.h"
#include "KitchenStaff.h"
#include "NormalChef.h"
#include "order/Order.h"
#include "staff/Waiter.h"
#include "subsystem/Meals/Meal.h"
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
    Meal* getOrder(uint32_t);

    std::string toString();
    ~Kitchen();
};