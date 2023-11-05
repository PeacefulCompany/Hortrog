#include "../src/order/OrderComposite.h"
#include "../src/order/OrderItem.h"
#include <gtest/gtest.h>

TEST(OrderComposite, TO_JSON) {
    auto orderComp = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2));
    ASSERT_EQ(orderComp->toJson(), "{\n\"order\": []\n}");
    orderComp->add(std::move(orderItem));
    ASSERT_EQ(orderComp->toJson(),
        "{\n\"order\": [\n{\"name\": \"bonger\",\"price\": 2.000000},]\n}");
}
TEST(OrderComposite, ADD) {
    auto orderComp = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2));
    auto orderComp2 = std::unique_ptr<Order>(new OrderComposite());
    orderComp->add(std::move(orderItem));
    orderComp->add(std::move(orderComp2));
    SUCCEED();
}
TEST(OrderComposite, TOTAL) {
    auto orderComp = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2));
    auto orderComp2 = std::unique_ptr<Order>(new OrderComposite());
    auto orderItem2 = std::unique_ptr<Order>(new OrderItem("sausgae", 4.12));
    orderComp2->add(std::move(orderItem2));
    orderComp->add(std::move(orderComp2));
    orderComp->add(std::move(orderItem));
    ASSERT_EQ(orderComp->total(), 6.12);
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}