#pragma once

#ifndef MEAL_H
#define MEAL_H

#include "MealItem.h"
#include "OrderTemplate/Order.h"
#include <string>
#include <vector>

class Meal {
public:

    // Constructors and Destructors
    Meal();
    Meal(std::unique_ptr<Order> order);
    ~Meal();

    //functions
    void addItem(MealItem* item);

    //getters and setters
    std::vector<MealItem*> getItems();
    void setItems(std::vector<MealItem*> items);
    bool getReady();
    void setReady(bool ready);
    std::unique_ptr<Order> getOrder();
    std::string getCustomer(){return order->getCustomer();};
    std::string getJson(){return order->toJson();};
    void setOrder(std::unique_ptr<Order> order);
    // std::vector<MealItem*>
private:
    std::unique_ptr<Order> order;
    std::vector<MealItem*> items;
    bool ready;
};

#endif // MEAL_H