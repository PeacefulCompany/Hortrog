#pragma once

#ifndef HEADCHEF_H
#define HEADCHEF_H

#include <string>
#include "Meal.h"

#include "MealItem.h"
#include "OrderTemplate/Order.h"
#include <string>
#include <vector>
#include <queue>
#include "Item.h"
#include "OrderJSON.h"
#include "KitchenStaff.h"

class Kitchen;

class HeadChef : public KitchenStaff
{
public:
    //constructors and destructors
    HeadChef(/* args */);
    HeadChef(std::string name, std::string role, int level, Kitchen* kitchen);
    ~HeadChef();

    //functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::vector<Item*> items);
    virtual void handlePreperation(std::vector<Item*> items, std::string customer);
    
    std::vector<Meal*> getPrepareMeals();
    void addMeal(Meal* meal);

    //getters and setters
    
private:
    std::vector<Meal*> mealsToPrepare;
    Kitchen* kitchen;
};

#include "Kitchen.h"


#endif // HEADCHEF_H