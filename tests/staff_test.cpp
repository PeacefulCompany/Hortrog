// #include "Customer/Customer.h"
// #include "Customer/KarenState.h"
// #include "Customer/OrderingState.h"
// #include "staff/Waiter.h"
// #include "subsystem\Meals\Meal.h"
// #include "gtest/gtest.h"
// class WaiterTest : public ::testing::Test {
// protected:
//     void SetUp() override {
//         menu = new Menu();
//         waiter = new Waiter(menu);
//     }

//     void TearDown() override {
//         delete waiter;
//         delete menu;
//     }
//     Menu* menu;
//     Waiter* waiter;
// };

#include "customer/Customer.h"
#include "customer/CustomerState.h"
#include "customer/EatingState.h"
#include "customer/KarenState.h"
#include "customer/OrderingState.h"
#include "customer/WaitingState.h"
#include "staff/Manager.h"
#include "staff/Waiter.h"
#include "gtest/gtest.h"
#include <cstddef>

class StaffTest : public ::testing::Test {
protected:
    void SetUp() override {
        menu = new Menu();
        waiter = new Waiter(menu);
        manager = new Manager();
        Customer* customer = new Customer("John Doe", 100);
    }
    void TearDown() override {
        delete waiter;
        delete manager;
        delete menu;
        delete customerState;
    }
    Menu* menu;
    Waiter* waiter;
    Manager* manager;
    CustomerState* customerState;
    Customer* customer;
};

// Tests for Waiter
TEST_F(StaffTest, Waiter_GetStaffTypeReturnsWaiter) {
    EXPECT_EQ(waiter->getStaffType(), "Waiter");
}
// Tests for Manager
TEST_F(StaffTest, Manager_GetStaffTypeReturnsManager) {
    EXPECT_EQ(manager->getStaffType(), "Manager");
}

TEST_F(StaffTest, Waiter_GetTablesReturnsEmptyVector) {
    EXPECT_TRUE(waiter->getTables().empty());
}

// Tests for Customer States
TEST_F(StaffTest, CustomerState_VisitWaiter) {
    EXPECT_EQ(customer->getState(), false);
}
// Tests for Customer States
TEST_F(StaffTest, CustomerState_VisitManager) {
    EXPECT_EQ(customer->getState(), false);
    customer->interact(*waiter);
}
// Test for Ordering State for waiter
TEST_F(StaffTest, OrderingState_VisitWaiter) {
    customer->changeState(new OrderingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder(), nullptr);
}
// Test for Ordering State for manager
TEST_F(StaffTest, OrderingState_VisitManager) {
    customer->changeState(new OrderingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*manager);
}

// Test for Waiting State for waiter
TEST_F(StaffTest, WaitingState_VisitWaiter) {
    customer->changeState(new WaitingState(customer));
    EXPECT_EQ(customer->getState(), true);
    customer->interact(*waiter);
    EXPECT_NE(waiter->getOrderBuilder(), nullptr);
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
// Tests for Waiter checkKitchen
TEST_F(StaffTest, CheckKitchenDoesNotThrow) {
    EXPECT_NO_THROW(waiter->checkKitchen());
}
// Tests for Waiter FetchMeals
TEST_F(StaffTest, FetchMealsDoesNotThrow) {
    EXPECT_NO_THROW(waiter->FetchMeals());
}
// Tests for Waiter Givetokitchen
TEST_F(StaffTest, GiveToKitchenDoesNotThrow) {
    EXPECT_NO_THROW(waiter->Givetokitchen());
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