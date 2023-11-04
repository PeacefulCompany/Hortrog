#include "OrderingState.h"
#include "Menu/Menu.h"
#include "customer/WaitingState.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include <iostream>

void OrderingState::visit(Manager& m) {
    if (readyTimer_.expired()) {
        std::cout << "Ordering: Manager" << std::endl;
    } else {
        std::cout << "Manager visited" << std::endl;
    }
}
// void Customer::buildOrder(OrderBuilder& builder) {}
void OrderingState::visit(Waiter& w) {
    if (readyTimer_.expired()) {
        OrderBuilder* TableOrder = w.getOrderBuilder();
        std::cout << "Ordering: Waiter" << std::endl;
        Menu* menu = TableOrder->getMenu();
        TableOrder->addItem("Burger");
        TableOrder->addModifier("Extra Patty");
        customer_->changeState(new WaitingState(customer_));
    } else {
        std::cout << "Not ready to order" << std::endl;
    }
}
void OrderingState::update(float dt) { readyTimer_.update(dt); }
