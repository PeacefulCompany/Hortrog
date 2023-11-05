
#include "HeadChef.h"

HeadChef::HeadChef(int rating, int capacity, Kitchen* kitchen, int speed, std::string role) {
    this->rating_ = rating;
    this->capacity_ = capacity;
    this->kitchen_ = kitchen;
    this->speed_ = speed;
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
    lastTime_ = 0;
    std::cout << "Head Chef: is checking a meal" << std::endl;
    OrderJSON* orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<Item*> items = orderJSON->getItems();

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
    std::string output = this->role_+":\n";
    output += "Rating: " + std::to_string(rating_) + "\n";
    output += "Capacity: " + std::to_string(capacity_) + "\n";
    output += "Speed: " + std::to_string(speed_) + "\n";
    return output;
}
