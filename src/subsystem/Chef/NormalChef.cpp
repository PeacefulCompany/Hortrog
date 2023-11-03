/**
 * @file NormalChef.cpp
 * @brief Implementation of the NormalChef class
 * 
 * This file contains the implementation of the NormalChef class, which is a subclass of KitchenStaff.
 * NormalChef objects are responsible for preparing meals by checking if they can prepare the items in the meal's order,
 * and either adding the item to a meal if it has already been prepared or preparing the item if it has not yet been prepared.
 * NormalChef objects have a rating, capacity, and speed, and can prepare a list of items.
 * 
 */
#include "NormalChef.h"
#include <iostream>

NormalChef::NormalChef()
{
    rating = 1;
    capacity = 1;
    kitchen = nullptr;
    nextStaff_ = nullptr;
}


NormalChef::NormalChef(int rating, int capacity, Kitchen *kitchen, int speed)
{
    this->rating = rating;
    this->capacity = capacity;
    this->kitchen = kitchen;
    nextStaff_ = nullptr;
    this->speed = speed;
}

NormalChef::~NormalChef()
{
}

void NormalChef::prepareMeal(Meal *meal)
{
    std::cout<<"Printing 1"<<std::endl;
    OrderJSON *orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<Item *> items = orderJSON->getItems();
    std::cout<<"State of can prepare array"<<std::endl;
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        std::cout<<canPrepareItems_[i]<<std::endl;
    }
    for (int i = 0; i < items.size(); i++)
    {
        std::cout<<"Printing 2"<<std::endl;
        if (canPrepareItem(items[i]->getName()))
        {
            std::cout<<"Printing 3"<<std::endl;
            if (mealItemAlreadyPrepared(items[i], meal))
            {
                std::cout << "Normal Chef is adding the item to a meal: " << items[i]->getName() << std::endl;
                getItemFromPrepared(items[i], meal);
            }
            else if( itemsBeingPrepared.size() < capacity && !mealItemAlreadyBeingPrepared(items[i], meal))
            {
                std::cout << "Normal Chef is preparing the item: " << items[i]->getName() << std::endl;
                MealItem *mealItem = new MealItem(meal->getCustomer(), this->rating, items[i]->getName(), items[i]->getDiet(), items[i]->getMod());
                // wait();
                itemsBeingPrepared.push_back(mealItem);
                std::cout << "Items being prepared by Normal Chef: " << std::endl;
                for (int i = 0; i < itemsBeingPrepared.size(); i++)
                {
                    std::cout << "Item " << i+1 << ": " << itemsBeingPrepared[i]->getFood() << std::endl;
                }
                // notify();
            }
        }
    }
    std::cout << "Normal Chef is done preparing the meal" << std::endl;
    KitchenStaff::prepareMeal(meal);
}

void NormalChef::getItemFromPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < preparedItems.size(); i++)
    {
        if (preparedItems[i]->getFood() == item->getName() && preparedItems[i]->getCustomer() == meal->getCustomer())
        {
            meal->addItem(preparedItems[i]);
            preparedItems.erase(preparedItems.begin() + i);
        }
    }
}

bool NormalChef::mealItemAlreadyPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < preparedItems.size(); i++)
    {
        if (preparedItems[i]->getFood() == item->getName() && preparedItems[i]->getCustomer() == meal->getCustomer())
        {
            return true;
        }
    }
    return false;
}

bool NormalChef::mealItemAlreadyBeingPrepared(Item *item, Meal* meal)
{
    for (int i = 0; i < itemsBeingPrepared.size(); i++)
    {
        if (itemsBeingPrepared[i]->getFood() == item->getName() && itemsBeingPrepared[i]->getCustomer() == meal->getCustomer())
        {
            return true;
        }
    }
    return false;
}

bool NormalChef::canPrepareItem(std::string item)
{
    std::cout<<"Printing 4"<<std::endl;
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        std::cout<<"CPI: "<<canPrepareItems_[i]<<std::endl;
        std::cout<<"IT: "<<item<<std::endl;
        if (canPrepareItems_[i] == item)
        {
            return true;
        }
    }
    std::cout<<"Returning false"<<std::endl;
    return false;
}

void NormalChef::addCanPrepareItem(std::string item)
{
    canPrepareItems_.push_back(item);
}

void NormalChef::removeCanPrepareItem(std::string item)
{
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        if (canPrepareItems_[i] == item)
        {
            canPrepareItems_.erase(canPrepareItems_.begin() + i);
        }
    }
}

void NormalChef::update(){
    // lastTime = 0;
    std::cout<<"Update Called"<<std::endl;
    std::cout<<"Value of itemsBeingPrepared: "<<itemsBeingPrepared.empty()<<std::endl;
    std::cout<<"Value of lastTime: "<<lastTime<<", Value of speed: "<<speed<<std::endl;
    if(!itemsBeingPrepared.empty() && lastTime >= speed)
    {
        std::cout<<"Condition met for update"<<std::endl;
        preparedItems.push_back(itemsBeingPrepared.front());
        itemsBeingPrepared.erase(itemsBeingPrepared.begin());
        print();
    }
    notify();

}

void NormalChef::print(){
    std::cout << "Normal Chef: " << std::endl;
    std::cout << "    Rating: " << rating << std::endl;
    std::cout << "    Capacity: " << capacity << std::endl;
    std::cout << "    Speed: " << speed << std::endl;
    std::cout << "    Can prepare: " << std::endl;
    for (int i = 0; i < canPrepareItems_.size(); i++)
    {
        std::cout << "        " << canPrepareItems_[i] << std::endl;
    }
    std::cout << "    Prepared Items: " << std::endl;
    for (int i = 0; i < preparedItems.size(); i++)
    {
        std::cout << "        " << preparedItems[i]->getFood() << " for " << preparedItems[i]->getCustomer() << std::endl;
    }
    std::cout << "    Items Being Prepared: " << std::endl;
    for (int i = 0; i < itemsBeingPrepared.size(); i++)
    {
        std::cout << "        " << itemsBeingPrepared[i]->getFood() << " for " << itemsBeingPrepared[i]->getCustomer() << std::endl;
    }
}


void NormalChef::wait()
{
    std::chrono::system_clock::time_point current_time =
        std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end_time =
        current_time + std::chrono::seconds(capacity);

    while (current_time < end_time)
    {
        current_time = std::chrono::system_clock::now();
    }
}