#pragma once

#ifndef HEADCHEF_H
#define HEADCHEF_H

#include "KitchenStaff.h"
#include "../menu/OrderJSON.h"

class HeadChef :public KitchenStaff
{
private:
    
public:
    HeadChef(int rating, int capacity, Kitchen* kitchen, int speed);
    void print();
    ~HeadChef();

    void prepareMeal(Meal* meal);
    
};


#endif