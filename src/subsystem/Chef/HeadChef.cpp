#include "HeadChef.h"

HeadChef::HeadChef(int rating, int capacity, Kitchen* kitchen, int speed) {
    this->rating = rating;
    this->capacity = capacity;
    this->kitchen = kitchen;
    this->speed = speed;
}

HeadChef::~HeadChef() {}

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