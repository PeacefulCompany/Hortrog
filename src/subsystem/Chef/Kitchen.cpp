/**
 * @file Kitchen.cpp
 * @brief Implementation of the Kitchen class.
 *
 * This file contains the implementation of the Kitchen class, which is
 * responsible for handling orders and preparing meals. It contains functions
 * for handling orders, meals, and clearing the queue. It also contains
 * functions for notifying when an item is ready and for flushing the queue.
 * Additionally, it contains functions for getting outgoing meals and updating
 * the time.
 */
#include "Kitchen.h"
#include "subsystem/Chef/KitchenStaff.h"
#include "subsystem/Chef/NormalChef.h"
#include <iostream>

// Kitchen::Kitchen() {

// }

// Kitchen::~Kitchen() {}

// void Kitchen::handleOrder(Order* order) {

//     std::cout << "Kitchen handling order" << std::endl;
//     std::cout << order->toJson() << std::endl;
//     Meal* meal = new Meal(order);
//     // handleMeal(meal);
//     while(meal->isReady() == false){
//     std::cout << "readyness" << meal->isReady() << std::endl;

//         std::cout << "meal is not ready" << std::endl;
//         headChef->prepareMeal(meal);
//         std::cout << meal->toString() << std::endl;
//     std::cout << "Kitchen handled order" << std::endl;

//     }
//     std::cout << "Kitchen handled order" << std::endl;
// }

// void Kitchen::handleMeal(Meal* meal) {
//     std::cout << "Kitchen checking meal" << std::endl;
//     if(meal->isReady()) {
//         outGoingMeals.push_back(meal);
//         printReadyMeals();
//         return;
//     }
//     else
//     {
//         incomingMeals.push(meal);
//     }
//     clearQueue();
//     std::cout << "Kitchen checked meal" << std::endl;

// }

// void Kitchen::clearQueue() {
//     std::cout << "Kitchen clearing queue" << std::endl;
//     while (!incomingMeals.empty()) {
//         std::cout << "Kitchen preparing meal" << std::endl;
//         headChef->prepareMeal(incomingMeals.front());
//         incomingMeals.pop();
//     }
//     std::cout << "Kitchen cleared queue" << std::endl;
// }

// void Kitchen::printReadyMeals() {
//     std::cout << "Kitchen printing ready meals" << std::endl;
//     for (auto& meal : outGoingMeals) {
//         std::cout << meal->toString() << std::endl;
//     }
//     std::cout << "Kitchen printed ready meals" << std::endl;
// }

Kitchen::Kitchen(/* args */) {
    this->headChef = std::unique_ptr<KitchenStaff>(new HeadChef(5, 5, this, 1, "head chef"));

    KitchenStaff* chef1 = new NormalChef(4, 5, this, 2, "fast chef 1");
    ((NormalChef*)chef1)->addCanPrepareItem("Grilled Salmon");
    ((NormalChef*)chef1)->addCanPrepareItem("Margherita Pizza");

    KitchenStaff* chef2 = new NormalChef(2, 5, this, 3, "medium chef 1");
    ((NormalChef*)chef2)->addCanPrepareItem("Avocado Toast");
    ((NormalChef*)chef2)->addCanPrepareItem("Chicken Caesar Salad");

    KitchenStaff* chef3 = new NormalChef(5, 5, this, 4, "slow chef 2");
    ((NormalChef*)chef3)->addCanPrepareItem("Vegetable Stir-Fry");
    ((NormalChef*)chef3)->addCanPrepareItem("Spinach and Feta Stuffed Chicken");

    KitchenStaff* chef4 = new NormalChef(4, 5, this, 3, "slow chef 2");
    ((NormalChef*)chef4)->addCanPrepareItem("Black Bean Burger");
    ((NormalChef*)chef4)->addCanPrepareItem("Beef Tacos");

    KitchenStaff* chef5 = new NormalChef(3, 5, this, 1, "barrista");
    ((NormalChef*)chef5)->addCanPrepareItem("Lemonade");
    ((NormalChef*)chef5)->addCanPrepareItem("Coconut Water");

    headChef->setNextStaff(chef1);
    chef1->setNextStaff(chef2);
    // chef2->setNextStaff(chef3);
    // chef3->setNextStaff(chef4);
    // chef4->setNextStaff(chef5);
}

void Kitchen::handleOrder(Order* order) {
    std::cout << "Kitchen: recieved Order" << std::endl;
    Meal* meal = new Meal(order);
    incomingMeals.push(meal);
    // flush();
}

void Kitchen::notifyItemReady() {
    std::cout << "Kitchen: Notified of a ready item" << std::endl;
    flush();
}

void Kitchen::flush() {
    std::cout << "Kitchen: Flushing unhandled orders through the system"
              << std::endl;
    for (int i = 0; i < incomingMeals.size(); i++) {
        // Pop an element from the incomingMeals queue.
        Meal* meal = incomingMeals.front();
        incomingMeals.pop();

        // Get the headChef to prepare the meal.
        headChef->prepareMeal(meal);

        // Check if the meal is done.
        if (meal->getReady()) {
            // If the meal is done, add it to the outgoingMeals vector.
            outgoingMeals.push_back(meal);
        } else {
            // If the meal is not done, re-add it to the incomingMeals queue.
            incomingMeals.push(meal);
        }
    }

    std::cout << "Kitchen: completed flushing orders through the system"
              << std::endl;
}

Meal* Kitchen::getOutgoingMeal() {
    if (outgoingMeals.empty()) {
        return nullptr;
    }
    Meal* meal = outgoingMeals.front();
    outgoingMeals.erase(outgoingMeals.begin());
    return meal;
}

void Kitchen::updateTime(int time) {
    std::cout << "Kitchen:" << time << " seconds hava passed" << std::endl;
    headChef->updateTime(time);
    flush();
    // std::cout << toString() << std::endl;
}

Kitchen::~Kitchen() {}

void Kitchen::subscribe(Waiter* waiter) { waiters_.push_back(waiter); }

void Kitchen::unsubscribe(Waiter* waiter) {
    waiters_.erase(
        std::remove(waiters_.begin(), waiters_.end(), waiter), waiters_.end());
}

std::vector<Meal*> Kitchen::collectOrders() {
    std::cout << "Kitchen: retrieving orders for waiter request" << std::endl;
    return outgoingMeals;
}

void Kitchen::notify() {
    std::cout << "Kitchen: notifying Waiters" << std::endl;
}

std::string Kitchen::toString() {
    std::string str = "=========================\n";
    str += "Kitchen: \n";
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    str += "Incoming Meals: \n";
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    for (int i = 0; i < incomingMeals.size(); i++) {
        str += incomingMeals.front()->toString() + "\n";
        incomingMeals.push(incomingMeals.front());
        incomingMeals.pop();
    }
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    str += "Outgoing Meals: \n";
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    for (int i = 0; i < outgoingMeals.size(); i++) {
        str += outgoingMeals[i]->toString() + "\n";
    }
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    str += "Kitchen Staff: \n";
    str += "+~~~~~~~~~~~~~~~~~~~~~~~+\n";
    KitchenStaff* current = headChef.get();
    while (current != nullptr) {
        str += "-------------------------\n";
        str += current->toString() + "\n";
        current = current->getNextStaff();
        str += "-------------------------\n";
    }
    str += "=========================\n";
    return str;
}