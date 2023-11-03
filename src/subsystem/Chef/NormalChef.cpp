/**
 * @file NormalChef.cpp
 * @brief Implementation of the NormalChef class
 *
 * This file contains the implementation of the NormalChef class, which is a
 * subclass of KitchenStaff. NormalChef objects are responsible for preparing
 * meals by checking if they can prepare the items in the meal's order, and
 * either adding the item to a meal if it has already been prepared or preparing
 * the item if it has not yet been prepared. NormalChef objects have a rating,
 * capacity, and speed, and can prepare a list of items.
 *
 */
#include "NormalChef.h"
#include <iostream>

/**
 * @brief Default constructor for NormalChef class
 *
 */
NormalChef::NormalChef() {
    rating_ = 1;
    capacity_ = 1;
    kitchen_ = nullptr;
    nextStaff_ = nullptr;
}

/**
 * @brief Constructor for NormalChef class
 *
 * @param rating The rating of the chef
 * @param capacity The capacity of the chef
 * @param kitchen The kitchen the chef is in
 * @param speed The speed of the chef
 */
NormalChef::NormalChef(int rating, int capacity, Kitchen* kitchen, int speed) {
    this->rating_ = rating;
    this->capacity_ = capacity;
    this->kitchen_ = kitchen;
    nextStaff_ = nullptr;
    this->speed_ = speed;
    this->role_ = "Normal Chef";
}

/**
 * @brief Destructor for NormalChef class
 *
 */
NormalChef::~NormalChef() {}

/**
 * @brief Prepares a meal by checking if the items in the meal's order can be
 * prepared
 *
 * @param meal The meal to be prepared
 */
void NormalChef::prepareMeal(Meal* meal) {
    OrderJSON* orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<Item*> items = orderJSON->getItems();

    for (int i = 0; i < items.size(); i++) {
        if (canPrepareItem(items[i]->getName())) {

            if (mealItemAlreadyPrepared(items[i], meal)) {
                std::cout << "Normal Chef is adding the item to a meal: "
                          << items[i]->getName() << std::endl;
                getItemFromPrepared(items[i], meal);

            } else if (itemsBeingPrepared_.size() < capacity_ &&
                       !mealItemAlreadyBeingPrepared(items[i], meal)) {
                std::cout << "Normal Chef is preparing the item: "
                          << items[i]->getName() << std::endl;

                MealItem* mealItem = new MealItem(meal->getCustomer(),
                    this->rating_,
                    items[i]->getName(),
                    items[i]->getDiet(),
                    items[i]->getMod());

                itemsBeingPrepared_.push_back(mealItem);
            }
        }
    }
    // std::cout << "Normal Chef is done preparing the meal" << std::endl;
    KitchenStaff::prepareMeal(meal);
}

/**
 * @brief Gets an item from the list of prepared items and adds it to the meal
 *
 * @param item The item to be added to the meal
 * @param meal The meal to add the item to
 */
void NormalChef::getItemFromPrepared(Item* item, Meal* meal) {
    for (int i = 0; i < preparedItems_.size(); i++) {
        if (preparedItems_[i]->getFood() == item->getName() &&
            preparedItems_[i]->getCustomer() == meal->getCustomer()) {
            meal->addItem(preparedItems_[i]);
            preparedItems_.erase(preparedItems_.begin() + i);
        }
    }
}

/**
 * @brief Checks if an item in a meal's order has already been prepared
 *
 * @param item The item to check
 * @param meal The meal to check
 * @return true if the item has already been prepared, false otherwise
 */
bool NormalChef::mealItemAlreadyPrepared(Item* item, Meal* meal) {
    for (int i = 0; i < preparedItems_.size(); i++) {
        if (preparedItems_[i]->getFood() == item->getName() &&
            preparedItems_[i]->getCustomer() == meal->getCustomer()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if an item in a meal's order is already being prepared
 *
 * @param item The item to check
 * @param meal The meal to check
 * @return true if the item is already being prepared, false otherwise
 */
bool NormalChef::mealItemAlreadyBeingPrepared(Item* item, Meal* meal) {
    for (int i = 0; i < itemsBeingPrepared_.size(); i++) {
        if (itemsBeingPrepared_[i]->getFood() == item->getName() &&
            itemsBeingPrepared_[i]->getCustomer() == meal->getCustomer()) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Checks if the chef can prepare a certain item
 *
 * @param item The item to check
 * @return true if the chef can prepare the item, false otherwise
 */
bool NormalChef::canPrepareItem(std::string item) {
    for (int i = 0; i < canPrepareItems_.size(); i++) {
        if (canPrepareItems_[i] == item) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Adds an item to the list of items the chef can prepare
 *
 * @param item The item to add
 */
void NormalChef::addCanPrepareItem(std::string item) {
    canPrepareItems_.push_back(item);
}

/**
 * @brief Removes an item from the list of items the chef can prepare
 *
 * @param item The item to remove
 */
void NormalChef::removeCanPrepareItem(std::string item) {
    for (int i = 0; i < canPrepareItems_.size(); i++) {
        if (canPrepareItems_[i] == item) {
            canPrepareItems_.erase(canPrepareItems_.begin() + i);
        }
    }
}

/**
 * @brief Updates the chef's list of prepared items
 *
 */
void NormalChef::update() {
    // lastTime = 0;
    if (!itemsBeingPrepared_.empty() && lastTime_ >= speed_) {
        preparedItems_.push_back(itemsBeingPrepared_.front());
        itemsBeingPrepared_.erase(itemsBeingPrepared_.begin());
        print();
    }
    notify();
}

/**
 * @brief Prints the chef's information
 *
 */
void NormalChef::print() {
    std::cout << "Normal Chef: " << std::endl;
    std::cout << "    Rating: " << rating_ << std::endl;
    std::cout << "    Capacity: " << capacity_ << std::endl;
    std::cout << "    Speed: " << speed_ << std::endl;
    std::cout << "    Can prepare: " << std::endl;
    for (int i = 0; i < canPrepareItems_.size(); i++) {
        std::cout << "        " << canPrepareItems_[i] << std::endl;
    }
    std::cout << "    Prepared Items: " << std::endl;
    for (int i = 0; i < preparedItems_.size(); i++) {
        std::cout << "        " << preparedItems_[i]->getFood() << " for "
                  << preparedItems_[i]->getCustomer() << std::endl;
    }
    std::cout << "    Items Being Prepared: " << std::endl;
    for (int i = 0; i < itemsBeingPrepared_.size(); i++) {
        std::cout << "        " << itemsBeingPrepared_[i]->getFood() << " for "
                  << itemsBeingPrepared_[i]->getCustomer() << std::endl;
    }
}

/**
 * @brief Causes the chef to wait for a certain amount of time
 *
 */
void NormalChef::wait() {
    std::chrono::system_clock::time_point current_time =
        std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end_time =
        current_time + std::chrono::seconds(capacity_);

    while (current_time < end_time) {
        current_time = std::chrono::system_clock::now();
    }
}