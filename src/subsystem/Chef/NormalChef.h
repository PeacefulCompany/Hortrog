#pragma once

#ifndef NORMALCHEF_H
#define NORMALCHEF_H

#include <string>
#include "Meal.h"

#include "MealItem.h"
#include "OrderTemplate/Order.h"
#include <string>
#include <vector>
#include <queue>

#include "KitchenStaff.h"
#include "Item.h"
#include "OrderJSON.h"
#include "HeadChef.h"
#include "../core/Timer.h"
#include <chrono>

class NormalChef : public KitchenStaff
{
public:
    //constructors and destructors
    NormalChef(/* args */);
    NormalChef(std::string name, std::string role, int level, int timeToPrepare, Kitchen* kitchen);
    ~NormalChef();

    //functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::string items);
    virtual void handlePreperation(Meal* meal);
    virtual void wait();
    // virtual void notify();

    //getters and setters
    void addPreparableItem(std::string itemName);
    void removePreparableItem(std::string itemName);
    // MealItem* getPreparedItem();

    protected:
    //attributes
    std::vector<MealItem*> mealItems;
    std::vector<std::string> preparableItems;
    int timeToPrepare;
};


#endif // NORMALCHEF_H