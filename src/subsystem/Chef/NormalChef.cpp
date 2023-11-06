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
NormalChef::NormalChef(
    int rating, int capacity, Kitchen* kitchen, int speed, std::string role) {
    this->rating_ = rating;
    this->capacity_ = capacity;
    this->kitchen_ = kitchen;
    nextStaff_ = nullptr;
    this->speed_ = speed;
    this->role_ = role;
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
    std::cout << "Normal Chef: is checking a meal" << std::endl;

    OrderJSON* orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<ItemJSON*> items = orderJSON->getItems();

    for (int i = 0; i < items.size(); i++) {
        if (canPrepareItem(items[i]->getName())) {

            if (mealItemAlreadyPrepared(items[i], meal)) {
                std::cout << "Normal Chef: adding prepared item to a meal "
                          << items[i]->getName() << std::endl;
                getItemFromPrepared(items[i], meal);

            } else if (itemsBeingPrepared_.size() < capacity_ &&
                       !mealItemAlreadyBeingPrepared(items[i], meal)) {

                MealItem* mealItem = new MealItem(items[i]->getCustomer(),
                    this->rating_,
                    items[i]->getName(),
                    items[i]->getDiet(),
                    items[i]->getMod());

                if (!meal->containsMealItem(mealItem)) {
                    std::cout
                        << "Normal Chef: preparing an item required by a meal "
                        << items[i]->getName() << std::endl;
                    itemsBeingPrepared_.push_back(mealItem);
                }
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
void NormalChef::getItemFromPrepared(ItemJSON* item, Meal* meal) {
    for (int i = 0; i < preparedItems_.size(); i++) {
        if (preparedItems_[i]->getFood() == item->getName() &&
            preparedItems_[i]->getCustomer() == item->getCustomer()) {
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
bool NormalChef::mealItemAlreadyPrepared(ItemJSON* item, Meal* meal) {
    for (int i = 0; i < preparedItems_.size(); i++) {
        if (preparedItems_[i]->getFood() == item->getName() &&
            preparedItems_[i]->getCustomer() == item->getCustomer()) {
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
bool NormalChef::mealItemAlreadyBeingPrepared(ItemJSON* item, Meal* meal) {
    for (int i = 0; i < itemsBeingPrepared_.size(); i++) {
        if (itemsBeingPrepared_[i]->getFood() == item->getName() &&
            itemsBeingPrepared_[i]->getCustomer() == item->getCustomer()) {
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
        lastTime_ = 0;
    }
    notify();
}

/**
 * @brief Prints the chef's information
 *
 */
std::string NormalChef::toString() {
    std::stringstream ss;
    ss << role_ << " (rating=" << rating_;
    ss << ", capacity=" << capacity_ << ", speed=" << speed_ << ")";
    ss << "\n- can_prepare: [";
    for (int i = 0; i < canPrepareItems_.size(); i++) {
        if (i != 0) ss << ", ";
        ss << canPrepareItems_[i];
    }
    ss << "]\n- pending:";

    for (int i = 0; i < preparedItems_.size(); i++) {
        ss << "\n  - " << preparedItems_[i]->getFood() << " for "
           << preparedItems_[i]->getCustomer() << std::endl;
    }
    ss << "\n- done:" << std::endl;
    for (int i = 0; i < itemsBeingPrepared_.size(); i++) {
        ss << "\n  - " << itemsBeingPrepared_[i]->getFood() << " for "
           << itemsBeingPrepared_[i]->getCustomer() << std::endl;
    }
    return ss.str();
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