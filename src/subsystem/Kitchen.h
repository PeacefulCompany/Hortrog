#pragma once
#include <memory>
#include <queue>
#include <vector>
#ifndef KITCHEN_H
#define KITCHEN_H
#include "subsystem/Meal.h"

class Kitchen {
private:
    std::vector<Waiter*> waiters_;
    std::unique_ptr<KitchenStaff> chef_ = std::make_unique<KitchenStaff>();
    std::queue<Order*> incoming_;
    std::queue<Meal> pending_;
    std::vector<Meal> outgoing_;
public:
    void notify ();
    void subscribe (Waiter* waiter);
    void unsubscribe (Waiter* waiter);
    void addOrder (Order* order);
    Order getOrder(int table);
};

#endif // KITCHEN_H