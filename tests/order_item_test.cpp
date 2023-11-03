#include "../src/order/OrderComposite.h"
#include "../src/order/OrderItem.h"
#include <gtest/gtest.h>

TEST(OrderItem, TO_JSON) {
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2));
    ASSERT_EQ(
        orderItem->toJson(), "{\"name\": \"bonger\",\"price\": 2.000000}");
}
TEST(OrderItem, TOTAL) {
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2.1));
    ASSERT_EQ(orderItem->total(), 2.1);
}
TEST(OrderItem, SET_GET_PRICE) {
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2.1));
    orderItem->setPrice(2.2);
    ASSERT_EQ(orderItem->getPrice(), 2.2);
}
TEST(OrderItem, GET_ID) {
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2.1));
    ASSERT_EQ(orderItem->getId(), "bonger");
}
// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }