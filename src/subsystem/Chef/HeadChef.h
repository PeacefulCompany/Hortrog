#pragma once

#ifndef HEADCHEF_H
#define HEADCHEF_H

#include <string>
#include "Meal.h"

#include "MealItem.h"
#include "OrderTemplate/Order.h"
#include <string>
#include <vector>

#include "KitchenStaff.h"

class HeadChef : public KitchenStaff
{
public:
    HeadChef(/* args */);
    ~HeadChef();
    
private:
    /* data */
};


#endif // HEADCHEF_H