#include "OrderingState.h"
#include "customer/WaitingState.h"
#include "floor/Table.h"
#include "menu/Menu.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void OrderingState::visit(Manager& m) {
    if (readyTimer_.expired()) {
        std::cout << "Ordering: Manager" << std::endl;
    } else {
        std::cout << "Manager visited" << std::endl;
    }
}
void OrderingState::visit(Waiter& w) {
    OrderBuilder* TableOrder = w.getOrderBuilder();
    const Menu* menu = TableOrder->getMenu();
    std::vector<std::string> allItems = menu->getAllKeys();
    int randomNumber = std::rand() % allItems.size();
    if (readyTimer_.expired()) {
        TableOrder->addItem(allItems[randomNumber], customer_->getName());
        int randomNumber = std::rand() % 100;
        if (std::rand() % 4 == 0) {
            std::string modifierName = "Wubba lubba dub dub!";
            // allItems[randomNumber].getModifiers()[0].getName();
            TableOrder->addModifier(modifierName);
        }
        customer_->changeState(new WaitingState(customer_));
    } else {
        readyTimer_.update(1); // to be removed
        std::cout << "Not ready to order" << std::endl;
    }
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }
