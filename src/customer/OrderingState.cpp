#include "OrderingState.h"
#include "Menu/Menu.h"
#include "customer/WaitingState.h"
#include "floor/Table.h"
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
    ConcreteOrderBuilder* TableOrder =
        static_cast<ConcreteOrderBuilder*>(w.getOrderBuilder());
    Menu* menu = TableOrder->getMenu();
    std::vector<Item>& allItems = menu->getAllItems();
    int randomNumber = std::rand() % allItems.size();
    std::cout << randomNumber << std::endl;

    if (readyTimer_.expired()) {
        std::string keyName = allItems[randomNumber].getName();
        TableOrder->addItem(keyName);
        customer_->changeState(new WaitingState(customer_));
    } else {
        readyTimer_.update(1);
        std::cout << "Not ready to order" << std::endl;
    }
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }
