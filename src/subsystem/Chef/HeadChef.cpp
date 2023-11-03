
#include "HeadChef.h"

HeadChef::HeadChef(int rating, int capacity, Kitchen* kitchen, int speed) {
    this->rating_ = rating;
    this->capacity_ = capacity;
    this->kitchen_ = kitchen;
    this->speed_ = speed;
}

HeadChef::~HeadChef() {}

/**
 * @brief Prepares a meal by checking if all the items in the order are present
 * and sets the meal as ready if so.
 *
 * @param meal A pointer to the Meal object to be prepared.
 */
void HeadChef::prepareMeal(Meal* meal) {
    std::cout << "Head Chef is preparing the meal" << std::endl;
    OrderJSON* orderJSON = new OrderJSON(meal->getOrder()->toJson());
    std::vector<Item*> items = orderJSON->getItems();

    if (items.size() == meal->getItems().size()) {
        std::cout << "meal is ready" << std::endl;
        meal->setReady(true);
        return;
    } else {
        meal->setReady(false);
        KitchenStaff::prepareMeal(meal);
    }

    std::cout << "Head Chef is done preparing the meal" << std::endl;
}