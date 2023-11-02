#pragma once

#ifndef NORMALCHEF_H
#define NORMALCHEF_H

#include "../Meals/Meal.h"
#include "../OrderTemplate/Order.h"
#include <queue>
#include <string>
#include <vector>

#include "../../core/Timer.h"
#include "../menu/Item.h"
#include "../menu/OrderJSON.h"
#include "HeadChef.h"
#include "KitchenStaff.h"
#include <chrono>

class NormalChef : public KitchenStaff {
public:
    // constructors and destructors
    NormalChef(/* args */);
    NormalChef(std::string name,
        std::string role,
        int level,
        int timeToPrepare,
        Kitchen* kitchen);
    ~NormalChef();

    // functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::string items);
    virtual void handlePreperation(Meal* meal);
    virtual void wait();
    // virtual void notify();

    // getters and setters
    void addPreparableItem(std::string itemName);
    void removePreparableItem(std::string itemName);
    // MealItem* getPreparedItem();

protected:
    // attributes
    std::vector<MealItem*> mealItems;
    std::vector<std::string> preparableItems;
    int timeToPrepare;
};

#endif // NORMALCHEF_H