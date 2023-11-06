#include "EatingState.h"
#include "customer/Customer.h"
#include "customer/OrderingState.h"
#include "customer/PayingState.h"
#include <iostream>
#include <stdlib.h>

void EatingState::visit(Manager& m) {
    if (eatTime_.expired() && this->customer_->getHappiness() < 10) {
        std::vector<std::string> complaints = {
            " was to cold'",
            " was to hot'",
            " was to spicy'",
            " was to salty'",
            " was to absulutly disgusting'",
            " was to dry'",
            " basicly tasted like nothing'",
            "was dog water'",
            "was not what I ordered'",
            "was not what I expected'",
            "was not what I wanted'",
        };
        srand(time(0));
        int randomIndex = rand() % complaints.size();
        m.lodgeComplaint(this->customer_->getName() + " says 'food  " +
                         complaints[randomIndex]);
        if (randomIndex < 2) {
            m.giveRating(2);
        } else {
            m.giveRating(1);
        }
        this->customer_->setHappiness(this->customer_->getHappiness() - 0.5);
    } else {
        if (this->customer_->getHappiness() < 30) {
            m.lodgeComplaint("Can you stop bothering me while I am eating");
        } else if (customer_->getHappiness() < 50) {
            m.lodgeComplaint("I am trying to eat here");
        } else if (customer_->getHappiness() < 70) {
            m.giveRating(3);
        } else if (customer_->getHappiness() < 90) {
            m.giveRating(4);
        } else if (customer_->getHappiness() < 100) {
            m.giveRating(5);
        }
        std::cout << "Manager visited" << std::endl;
    }
}
void EatingState::visit(Waiter& w) {
    if (this->customer_->getHappiness() < 5) {
        std::cout << this->customer_->getName() +
                         " says 'This does not tast right'"
                  << std::endl;
    } else
        std::cout << this->customer_->getName() + " says 'The food is Great'"
                  << std::endl;
}
void EatingState::update(float dt) {
    eatTime_.update(dt);
    if (eatTime_.expired()) {
        if (rand() % 2 == 0) {
            std::cout << "[Eating] Done eating, but I want more" << std::endl;
            customer_->changeState(new OrderingState(customer_));
        } else {
            std::cout << "[Eating] Done eating, let me pay" << std::endl;
            customer_->changeState(new PayingState(customer_));
        }
    } else {
        std::cout << "Still eating: "
                  << (eatTime_.duration() - eatTime_.current()) << std::endl;
    }
}
