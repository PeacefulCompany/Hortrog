#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include <gtest/gtest.h>

TEST(OrderItem, TO_JSON) {
    MenuItem item("bonger", 2, "", {});
    auto orderItem = std::unique_ptr<Order>(new OrderItem(&item));
    ASSERT_EQ(
        orderItem->toJson(), "{\"name\": \"bonger\",\"price\": 2.000000}");
}
TEST(OrderItem, TOTAL) {
    MenuItem item("bonger", 2, "", {});
    auto orderItem = std::unique_ptr<Order>(new OrderItem(&item));
    ASSERT_EQ(orderItem->total(), 2.1);
}
TEST(OrderItem, GET_ID) {
    MenuItem item("bonger", 2.1, "", {});
    auto orderItem = std::unique_ptr<Order>(new OrderItem(&item));
    ASSERT_EQ(orderItem->getId(), "bonger");
}
// int main(int argc, char** argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }