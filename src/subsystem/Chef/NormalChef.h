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

class NormalChef : public KitchenStaff
{
public:
    //constructors and destructors
    NormalChef(/* args */);
    NormalChef(std::string name, std::string role, int level);
    ~NormalChef();

    //functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::vector<Item*> items);
    virtual void handlePreperation(Meal* meal);

    //getters and setters
    std::string addPreparableItem(std::string itemName);
    std::string removePreparableItem(std::string itemName);

    protected:
    //attributes
    std::vector<MealItem*> mealItems;
    std::vector<std::string> preparableItems;
    HeadChef* headChef;
};


#endif // NORMALCHEF_H