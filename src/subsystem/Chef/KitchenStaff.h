#pragma once

#ifndef KITCHENSTAFF_H
#define KITCHENSTAFF_H

#include <string>
#include "Meal.h"

#include "MealItem.h"
#include "OrderTemplate/Order.h"
#include <string>
#include <vector>
#include "Item.h"
#include "OrderJSON.h"

class Kitchen;

class KitchenStaff
{
public:

    //constructors and destructors

    KitchenStaff(std::string name, std::string role, int level, Kitchen* kitchen);
    KitchenStaff();
    ~KitchenStaff();

    //functions
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::string items);
    virtual void handlePreperation(Meal* meal);
    virtual void notify();

    //getters and setters

    std::string getName() const;
    std::string getRole() const;
    int getLevel() const;
    KitchenStaff* getNext() const;

    void setName(std::string name);
    void setRole(std::string role);
    void setLevel(int level);
    void setNext(KitchenStaff* next);


protected:
    //attributes
    std::string name;
    std::string role;
    int level;
    KitchenStaff* next;
    Kitchen* kitchen;
    //functions

    
};

#include "Kitchen.h"

#endif // KITCHENSTAFF_H
