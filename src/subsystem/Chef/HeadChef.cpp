#include "HeadChef.h"

#include <sstream>

HeadChef::HeadChef(
    int rating, int capacity, Kitchen* kitchen, int speed, std::string role) {
    this->rating_ = rating;
    this->capacity_ = capacity;
    this->kitchen_ = kitchen;
    this->timer_ = Timer(speed);
    this->role_ = role;
}

HeadChef::~HeadChef() {}

/**
 * @brief Prepares a meal by checking if all the items in the order are present
 * and sets the meal as ready if so.
 *
 * @param meal A pointer to the Meal object to be prepared.
 */
void HeadChef::prepareMeal(Meal* meal) {
    timer_.reset();
    std::cout << "Head Chef: is checking a meal" << std::endl;
    OrderJSON* orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<ItemJSON*> items = orderJSON->getItems();

    if (items.size() == meal->getItems().size()) {
        std::cout << "Head Chef: meal is ready" << std::endl;
        meal->setReady(true);
        return;
    } else {
        meal->setReady(false);
        KitchenStaff::prepareMeal(meal);
    }

    // std::cout << "Head Chef is done preparing the meal" << std::endl;
}

/**
 * @brief Prints the Head Chef's information.
 *
 */
std::string HeadChef::toString() {
    std::stringstream ss;
    ss << role_ << " (rating=" << rating_;
    ss << ", capacity=" << capacity_ << ", speed=" << timer_.duration() << ")";

    return ss.str();
}
