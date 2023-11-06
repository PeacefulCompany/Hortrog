#pragma once

#include <chrono>
#include <sstream>
#include <string>
#include <vector>

#include "../Meals/Meal.h"
#include "../Meals/MealItem.h"
#include "../menu/OrderJSON.h"
#include "KitchenStaff.h"

class NormalChef : public KitchenStaff {
private:
    std::vector<std::string> canPrepareItems_;
    std::vector<MealItem*> preparedItems_;
    std::vector<MealItem*> itemsBeingPrepared_;
    virtual void update();

public:
    NormalChef();
    std::string toString();
    NormalChef(int rating,
        int capacity,
        Kitchen* kitchen,
        int speed,
        std::string role);
    void prepareMeal(Meal* meal);
    void getItemFromPrepared(ItemJSON* item, Meal* meal);
    bool canPrepareItem(std::string item);
    void addCanPrepareItem(std::string item);
    void removeCanPrepareItem(std::string item);
    bool mealItemAlreadyPrepared(ItemJSON* item, Meal* meal);
    bool mealItemAlreadyBeingPrepared(ItemJSON* item, Meal* meal);
    void wait();

    ~NormalChef();
};
