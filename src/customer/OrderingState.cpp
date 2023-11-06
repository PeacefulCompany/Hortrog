#include "OrderingState.h"
#include "customer/Customer.h"
#include "customer/WaitingState.h"
#include "floor/Table.h"
#include "menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

void OrderingState::visit(Manager& m) {
    if (readyTimer_.expired()) {
        std::vector<std::string> complaints = {
            "We have been waiting for a long time",
            "Slow service im starving",
            "Dirty utensils and where is the food",
            "Noisy atmosphere cant even get a drink",
            "can you please call a waiter so we can order",
            "I have been waiting for a long time",
            "Can i Get any Hungrier???  ",
        };
        srand(time(0));
        int randomIndex = rand() % complaints.size();
        m.lodgeComplaint(complaints[randomIndex]);
        this->customer_->setHappiness(this->customer_->getHappiness() - 5);
        // request a waiter
    } else {
        std::cout << "Manager talked to a cutomer" << std::endl;
        this->customer_->setHappiness(this->customer_->getHappiness() + 5);
    }
}
void OrderingState::visit(Waiter& w) {
    if (!readyTimer_.expired()) {
        std::cout << customer_->toString() << ": Not ready to order"
                  << std::endl;
        return;
    }

    OrderBuilder* orderBuilder = w.getOrderBuilder();
    const Menu* menu = orderBuilder->getMenu();
    std::vector<std::string> menuKeys = menu->getAllKeys();

    srand(time(0));
    int numItems = 1 + (std::rand() % 5);
    for (int i = 0; i < numItems; i++) {
        // Add random order item
        int j = std::rand() % menuKeys.size();
        std::string itemKey = menuKeys[j];
        orderBuilder->addItem(itemKey, customer_->getName());

        std::cout << customer_->toString() << ": I ordered " << itemKey;

        // Get supported modifiers
        const MenuItem* menuItem = menu->getMenuItem(itemKey);
        std::vector<std::string> modifierNames = menuItem->supportedModifiers();
        if (modifierNames.size() == 0) {
            std::cout << std::endl;
            continue;
        }

        // Select random modifier
        j = std::rand() % (modifierNames.size() * 2);
        if (j < modifierNames.size()) {
            orderBuilder->addModifier(modifierNames[j]);
        }
        std::cout << " with " << modifierNames[j] << std::endl;
    }
    customer_->setHappiness(this->customer_->getHappiness() + 5);
    customer_->changeState(new WaitingState(customer_));
    std::cout << orderBuilder->toString() << std::endl;
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }

std::string OrderingState::toString() const {
    std::stringstream ss;
    ss << "[Ordering] ";
    if (readyTimer_.expired()) {
        ss << "Ready to order";
    } else {
        ss << std::setprecision(5) << readyTimer_.remaining();
    }
    return ss.str();
}
