#include "Kitchen.h"
#include <iostream>

Kitchen::Kitchen() {
    headChef = std::make_unique<HeadChef>(HeadChef("Head Chef", "Head Chef", 1, this));
    headChef->setNext(new NormalChef("Normal Chef", "Normal Chef", 2, 5,this));
    ((NormalChef*) headChef->getNext())->addPreparableItem("Avocado Toast");
    ((NormalChef*) headChef->getNext())->addPreparableItem("Grilled Salmon");
    headChef->getNext()->setNext(new NormalChef("Normal Chef", "Normal Chef", 2, 5,this));

}

Kitchen::~Kitchen() {}


void Kitchen::handleOrder(Order* order) {

    std::cout << "Kitchen handling order" << std::endl;
    std::cout << order->toJson() << std::endl;
    Meal* meal = new Meal(order);
    // handleMeal(meal);
    while(meal->isReady() == false){
    std::cout << "readyness" << meal->isReady() << std::endl;

        std::cout << "meal is not ready" << std::endl;
        headChef->prepareMeal(meal);
        std::cout << meal->toString() << std::endl;
    std::cout << "Kitchen handled order" << std::endl;

    }
    std::cout << "Kitchen handled order" << std::endl;
}

void Kitchen::handleMeal(Meal* meal) {
    std::cout << "Kitchen checking meal" << std::endl;
    if(meal->isReady()) {
        outGoingMeals.push_back(meal);
        printReadyMeals();
        return;
    }
    else
    {
        incomingMeals.push(meal);
    }
    clearQueue();
    std::cout << "Kitchen checked meal" << std::endl;

}

void Kitchen::clearQueue() {
    std::cout << "Kitchen clearing queue" << std::endl;
    while (!incomingMeals.empty()) {
        std::cout << "Kitchen preparing meal" << std::endl;
        headChef->prepareMeal(incomingMeals.front());
        incomingMeals.pop();
    }
    std::cout << "Kitchen cleared queue" << std::endl;
}



void Kitchen::printReadyMeals() {
    std::cout << "Kitchen printing ready meals" << std::endl;
    for (auto& meal : outGoingMeals) {
        std::cout << meal->toString() << std::endl;
    }
    std::cout << "Kitchen printed ready meals" << std::endl;
}

void Kitchen::notify() { std::cout << "Kitchen notified" << std::endl; }