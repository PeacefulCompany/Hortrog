#pragma once

#ifndef NORMALCHEF_H
#define NORMALCHEF_H

#include <vector>
#include <string>
#include <chrono>

#include "KitchenStaff.h"
#include "../Meals/Meal.h"
#include "../Meals/MealItem.h"
#include "../menu/OrderJSON.h"

class NormalChef : public KitchenStaff
{
private:
    std::vector<std::string> canPrepareItems_;
    std::vector<MealItem *> preparedItems_;
    std::vector<MealItem *> itemsBeingPrepared_;
    virtual void update();

public:
    NormalChef();
    void print();
    NormalChef(int rating, int capacity, Kitchen *kitchen, int speed);
    void prepareMeal(Meal *meal);
    void getItemFromPrepared(Item *item, Meal* meal);
    bool canPrepareItem(std::string item);
    void addCanPrepareItem(std::string item);
    void removeCanPrepareItem(std::string item);
    bool mealItemAlreadyPrepared(Item *item, Meal* meal);
    bool mealItemAlreadyBeingPrepared(Item *item, Meal* meal);
    void wait();

    ~NormalChef();
};

#endif
