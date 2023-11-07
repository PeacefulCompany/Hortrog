#include "WaiterDemo.h"
#include "customer/OrderingState.h"
#include "customer/PayingState.h"

WaiterDemo::WaiterDemo() {
    menu_ = new Menu();
    menu_->loadFromFile("menu_items.json");
    pointOfSales_ = new PointOfSales();
    table_ = new TableComponent(1, 4);
    waiter_ = new Waiter(menu_, nullptr, nullptr, pointOfSales_);
    // orderBuilder_ = std::make_unique<ConcreteOrderBuilder>(menu_);
}

void WaiterDemo::placeCustomers() {
    for (auto& customer : customers_) {
        table_->seatCustomer(customer);
    }
}

void WaiterDemo::addCustomers() {
    customers_.push_back(new Customer("John", 5));
    customers_.push_back(new Customer("Jane", 15));
    customers_.push_back(new Customer("Jack", 10));
}

void WaiterDemo::customerOrder() {
    // set state of all customers to ordering
    waiter_->getOrderBuilder()->begin(1);
    for (auto& customer : customers_) {
        customer->changeState(new OrderingState(customer));
    }
    table_->update(1);
    // waiter takes order
    for (auto& customer : customers_) {
        customer->interact(*waiter_);
    }

    // waiter sends receipt thingy wingy

    Order* order = waiter_->getOrderBuilder()->getOrder();
    waiter_->getPointOfSales()->addOrder(order);

    for (auto& customer : customers_) {
        customer->changeState(new PayingState(customer));
    }

    for (auto& customer : customers_) {
        customer->interact(*waiter_);
    }
}
