#include "billing/Payment.h"
#include <gtest/gtest.h>


TEST(Payment, getAmt) {
    Payment payment(1,85.0);
    ASSERT_EQ(payment.getAmountOfPayment(), 85.0);
}

TEST(Payment, getTbl) {
    Payment payment(1,85.0);
    ASSERT_EQ(payment.gettableId(), 1);
}

TEST(Payment, copyConstructor) {
    Payment* payment=new Payment(1,85.0);
    Payment* copy=new Payment(payment);
    ASSERT_EQ(copy->getAmountOfPayment(), 85.0);
    ASSERT_EQ(copy->gettableId(), 1);
    delete copy;
    delete payment;
}

/*TEST(Payment, ADD) {
    MenuItem item("bonger", 2, "", {});
    auto orderComp = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem = std::unique_ptr<Order>(new OrderItem(&item));
    auto orderComp2 = std::unique_ptr<Order>(new OrderComposite());
    orderComp->add(std::move(orderItem));
    orderComp->add(std::move(orderComp2));
    SUCCEED();
}
TEST(Payment, TOTAL) {
    MenuItem item("bonger", 2, "", {});
    MenuItem item2("sausgae", 4.12, "", {});

    auto orderComp = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem = std::unique_ptr<Order>(new OrderItem(&item));
    auto orderComp2 = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem2 = std::unique_ptr<Order>(new OrderItem(&item2));
    orderComp2->add(std::move(orderItem2));
    orderComp->add(std::move(orderComp2));
    orderComp->add(std::move(orderItem));
    ASSERT_EQ(orderComp->total(), 6.12);
}*/

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}