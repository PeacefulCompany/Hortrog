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
    if (readyTimer_.expired()) {
        std::cout << "[OrderingState/visit] Not ready to order yet."
                  << std::endl;
        return;
    }

    OrderBuilder* builder = w.getOrderBuilder();
    builder->begin();

    const std::vector<Item>& items = builder->getMenu()->getAllItems();
    int numItems = std::rand() % 5 + 1;

    for (int i = 0; i < numItems; i++) {
        int item = std::rand() % items.size();
        builder->addItem(items[item].getName());
    }

    customer_->changeState(new WaitingState(customer_));
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }
