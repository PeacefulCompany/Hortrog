#pragma once

#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "../Meals/Meal.h"
#include <string>

#include "../OrderTemplate/Order.h"
#include "../menu/Item.h"
#include "../menu/OrderJSON.h"
#include "KitchenStaff.h"
#include <queue>
#include <string>
#include <vector>

class HeadChef : public KitchenStaff {
public:
    // constructors and destructors
    HeadChef(/* args */);
    HeadChef(std::string name, std::string role, int level, Kitchen* kitchen);
    ~HeadChef();

    // functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::string items);
    virtual void handlePreperation(Meal* meal);

    std::vector<Meal*> getPrepareMeals();
    void addMeal(Meal* meal);
    // void notify();

    // getters and setters

private:
    std::vector<Meal*> mealsToPrepare;
};

#endif // HEADCHEF_H