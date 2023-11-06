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


class StaffTest : public ::testing::Test {
protected:
    void SetUp() override {
        menu = new Menu();
        floor = new Floor();
        customer = new Customer("John Doe", 100);
        waiter = new Waiter(menu, floor);
        manager = new Manager(floor);
    }
    Menu* menu;
    Floor* floor;
    Waiter* waiter;
    Manager* manager;
    Customer* customer;
};
// WAITER
// TESTS==================================================================
//  Tests for Waiter
TEST_F(StaffTest, Waiter_GetStaffTypeReturnsWaiter) {
    EXPECT_EQ(waiter->getStaffType(), "Waiter");
}
// Tests for Customer
TEST_F(StaffTest, Waiter_GetTablesReturnsEmptyVector) {
    EXPECT_EQ(waiter->getStaffType(), "Waiter");
    EXPECT_TRUE(waiter->getTables().empty());
}

// MANAGER
// TESTS=================================================================
// Tests for Manager
TEST_F(StaffTest, Manager_GetStaffTypeReturnsManager) {
    EXPECT_EQ(manager->getStaffType(), "Manager");
}
// Tests for Manager
TEST_F(StaffTest, Manager_GetTablesReturnsEmptyVector) {
    EXPECT_EQ(manager->getStaffType(), "Manager");
}
// Tests for Customer States
TEST_F(StaffTest, CustomerState_VisitManager) {
    EXPECT_EQ(manager->getStaffType(), "Manager");
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
    EXPECT_EQ(customer->getHappiness(), 105);
}
// Tests for Customer
//=======================================================================
// Tests for Customer States
TEST_F(StaffTest, CustomerState_VisitWaiter) {
    EXPECT_EQ(customer->getState(), true);
}
// Test for Ordering State for waiter ready
TEST_F(StaffTest, OrderingState_VisitWaiterReady) {
    customer->changeState(new WaitingState(customer));
    customer->update(1);
    customer->interact(*waiter);
}

// Test for Waiting State for waiter not ready
TEST_F(StaffTest, WaitingState_VisitWaiter) {
    customer->changeState(new WaitingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder(), nullptr);
}
// Test for Waiting State for waiter Ready
TEST_F(StaffTest, WaitingState_VisitWaiterReady) {
    customer->changeState(new WaitingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder(), nullptr);
    customer->update(1);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder()->getOrder(), nullptr);
}
// Test for Waiting State for manager
TEST_F(StaffTest, WaitingState_VisitManager) {
    customer->changeState(new WaitingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
}
// Test for Eating State for waiter
TEST_F(StaffTest, EatingState_VisitWaiter) {
    customer->changeState(new EatingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder(), nullptr);
}
// Test for Waiting State for manager
TEST_F(StaffTest, EatingState_VisitManager) {
    customer->changeState(new EatingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
}

// Test for Karen State for waiter
TEST_F(StaffTest, KarenState_VisitWaiter) {
    customer->changeState(new KarenState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
}
// Test for Karen State for manager
TEST_F(StaffTest, KarenState_VisitManager) {
    customer->changeState(new KarenState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
}

// Test for Paying State for waiter
TEST_F(StaffTest, PayingState_VisitWaiter) {
    customer->changeState(new KarenState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
}
// Test for Paying State for manager
TEST_F(StaffTest, PayingState_VisitManager) {
    customer->changeState(new KarenState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
}

// Tests for Waiter giveFoodToCustomer
TEST_F(StaffTest, GiveFoodToCustomerDoesNotThrow) {
    EXPECT_NO_THROW(waiter->giveFoodToCustomer(*customer));
}
// Test for Manager lodgeComplaint
TEST_F(StaffTest, LodgeComplaintDoesNotThrow) {
    EXPECT_NO_THROW(manager->lodgeComplaint("Test"));
}
// Test for Manager giveRating
TEST_F(StaffTest, GiveRatingDoesNotThrow) {
    EXPECT_NO_THROW(manager->giveRating(5));
}
// end!
