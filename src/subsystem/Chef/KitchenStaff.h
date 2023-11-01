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

class KitchenStaff
{
public:

    //constructors and destructors

    KitchenStaff(std::string name, std::string role, int level);
    KitchenStaff();
    ~KitchenStaff();

    //functions
    
    virtual void prepareMeal(Meal* meal);
    virtual bool canPrepare(std::vector<Item*> items);
    virtual void handlePreperation(std::vector<Item*> items, std::string customer);


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

    //functions

    
};


#endif // KITCHENSTAFF_H
