#include <gtest/gtest.h>
#include "../src/order/OrderComposite.h"
#include "../src/order/OrderItem.h"

TEST(OrderComposite, ADD) {
    Order * orderComp = new OrderComposite();
    auto orderItem = std::shared_ptr<Order>(new OrderItem("bonger", 2));
    orderComp->add(orderItem);
}
TEST(OrderComposite, TOTAL) {
    Order * orderComp = new OrderComposite();
    auto orderComp2 = std::shared_ptr<Order>(new OrderComposite());
    auto orderItem = std::shared_ptr<Order>(new OrderItem("hortdog", 2));
    orderComp->add(orderComp2);
    orderComp2->add(orderItem);
    const auto actual = orderComp->total();
    const auto expected = 2.0;
    ASSERT_EQ(actual, expected);
}
TEST(OrderComposite, JSON){
    Order * orderComp = new OrderComposite();
    auto orderComp2 = std::shared_ptr<Order>(new OrderComposite());
    std::vector<std::shared_ptr<Order>> orderItemArr;
    std::string ids [] = {"hortdog", "burger", "pie"};
    double prices [] = {0.5, 5, 1};
    for (int i = 0; i < 3; i++) {
        orderItemArr.push_back(std::shared_ptr<Order>(new OrderItem(ids[i], prices[i])));
    }
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}