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
#include <iostream>
#include <memory>

Kitchen::Kitchen(/* args */) {
    staff_ = std::make_unique<HeadChef>(5, 5, this, 1, "head_chef");

    std::unique_ptr<NormalChef> chef = nullptr;

    chef = std::make_unique<NormalChef>(4, 5, this, 2, "fast_chef1");
    chef->addCanPrepareItem("Grilled Salmon");
    chef->addCanPrepareItem("Margherita Pizza");
    chef->setNextStaff(staff_.release());
    staff_ = std::move(chef);

    chef = std::make_unique<NormalChef>(2, 5, this, 3, "medium_chef1");
    chef->addCanPrepareItem("Avocado Toast");
    chef->addCanPrepareItem("Chicken Caesar Salad");
    chef->setNextStaff(staff_.release());
    staff_ = std::move(chef);

    chef = std::make_unique<NormalChef>(5, 5, this, 4, "slow_chef2");
    chef->addCanPrepareItem("Vegetable Stir-Fry");
    chef->addCanPrepareItem("Spinach and Feta Stuffed Chicken");
    chef->setNextStaff(staff_.release());
    staff_ = std::move(chef);

    chef = std::make_unique<NormalChef>(4, 5, this, 3, "slow_chef2");
    chef->addCanPrepareItem("Black Bean Burger");
    chef->addCanPrepareItem("Beef Tacos");
    chef->setNextStaff(staff_.release());
    staff_ = std::move(chef);

    chef = std::make_unique<NormalChef>(3, 5, this, 1, "barrista");
    chef->addCanPrepareItem("Lemonade");
    chef->addCanPrepareItem("Coconut Water");
    chef->setNextStaff(staff_.release());
    staff_ = std::move(chef);
}

void Kitchen::handleOrder(Order* order) {
    std::cout << "Kitchen: recieved Order" << std::endl;
    Meal* meal = new Meal(order);

    if (order->toJson() == "{}") {
        std::cout << "Kitchen: recieved empty order" << std::endl;
        return;
    }
    incomingMeals.push_back(meal);
    flush();
}

void Kitchen::AddChef(KitchenStaff* chef) {
    chef->setNextStaff(staff_.release());
    staff_.reset(chef);
}

void Kitchen::notifyItemReady() {
    std::cout << "Kitchen: Notified of a ready item" << std::endl;
    flush();
}

void Kitchen::flush() {
    std::cout << "-----------Kitchen flushing unhandled orders-----------"
              << std::endl;

    for (int i = 0; i < incomingMeals.size(); i++) {
        // Pop an element from the incomingMeals queue.
        Meal* meal = incomingMeals.front();
        incomingMeals.pop_front();

        // Get the headChef to prepare the meal.
        staff_->prepareMeal(meal);

        // Check if the meal is done.
        if (meal->getReady()) {
            // If the meal is done, add it to the outgoingMeals vector.
            outgoingMeals.push_back(meal);
            notify();
        } else {
            // If the meal is not done, re-add it to the incomingMeals queue.
            incomingMeals.push_back(meal);
        }
    }
    std::cout << "---------------Kitchen finished flushing---------------"
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
    std::cout << "[Kitchen]: " << time << "'s have passed" << std::endl;
    for (int i = 0; i < time; i++) {
        staff_->updateTime(1);
    }

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
    for (Waiter* w : waiters_) {
        w->checkKitchen();
    }
}

std::string Kitchen::toString() {
    std::stringstream ss;
    ss << "KITCHEN\n- incoming:";

    for (auto it = incomingMeals.begin(); it != incomingMeals.end(); it++) {
        ss << "\n  - " << (*it)->toString();
    }
    ss << "\n- outgoing:";
    for (int i = 0; i < outgoingMeals.size(); i++) {
        ss << "\n  - " << outgoingMeals[i]->toString();
    }
    ss << "\n- staff:";
    for (KitchenStaff* cur = staff_.get(); cur; cur = cur->getNextStaff()) {
        std::string line;
        std::stringstream stream(cur->toString());
        std::getline(stream, line);

        ss << "\n  - " << line;
        while (!stream.eof()) {
            std::getline(stream, line);
            ss << "\n    " << line;
        }
    }
    return ss.str();
}

Meal* Kitchen::getOrder(uint32_t tblId) {
    for (auto& meal : outgoingMeals) {
        if (meal->getOrder()->getTblId() == tblId) {
            return meal;
        }
    }
    return nullptr;
}