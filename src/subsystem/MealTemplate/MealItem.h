#pragma once

#ifndef MEALITEM_H
#define MEALITEM_H

#include <string>

class MealItem {
public:

    // Constructors and Destructors
    MealItem();
    MealItem(std::string customer, int quality, std::string food);
    ~MealItem();

    //functions


    // Getters
    std::string getCustomer();
    int getQuality();
    std::string getFood();

    // Setters
    void setCustomer(std::string customer);
    void setQuality(int quality);
    void setFood(std::string food);

private:
    std::string customer;
    int quality;
    std::string food;
};

#endif // MEALITEM_H