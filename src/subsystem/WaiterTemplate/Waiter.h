#pragma once
#include "subsystem/Chef/Kitchen.h"
#include "subsystem/Meals/Meal.h"
#ifndef SUBSYSTEM_WAITER_H
#define SUBSYSTEM_WAITER_H
class Waiter {

private:
    Kitchen* kitchen_;
    std::vector<Meal*> meals_;
public:
    void checkKitchen();
    Waiter(Kitchen*);

};

#endif // SUBSYSTEM_WAITER_H