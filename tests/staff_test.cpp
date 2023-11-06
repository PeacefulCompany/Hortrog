#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "customer/EatingState.h"
#include "customer/KarenState.h"
#include "customer/OrderingState.h"
#include "customer/WaitingState.h"
#include "menu/Menu.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include "gtest/gtest.h"
#include <cmath>
#include <cstddef>
#include <sstream>

TEST(StaffTest, TestCustomerOrderVisit) {
    const Menu menu = Menu();
    const Floor floor = Floor();
    Customer* c = new Customer("Bob", 1);
    Waiter* w = new Waiter(&menu, &floor);
    c->changeState(new WaitingState(c));
    c->update(1);
    c->interact(*w);
    c->changeState(new OrderingState(c));
    EXPECT_NE(w->getOrderBuilder(), nullptr);
}
TEST(StaffTest, TestManagerVisit) {
    const Menu menu = Menu();
    const Floor floor = Floor();
    Customer* c = new Customer("Bob", 1);
    Manager* m = new Manager(&floor);
    c->changeState(new WaitingState(c));
    c->update(1);
    c->interact(*m);
    c->changeState(new OrderingState(c));
    c->update(1);
    c->interact(*m);
    c->changeState(new EatingState(c));
    c->update(1);
}
