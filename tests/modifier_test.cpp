#include "../src/order/Modifier.h"
#include "../src/order/OrderComposite.h"
#include "../src/order/OrderItem.h"
#include <gtest/gtest.h>

TEST(Modifier, TOTAL) {
    auto component = std::unique_ptr<Order>(new OrderItem("ABC", 2.1));
    auto modifier =
        std::unique_ptr<Order>(new Modifier(std::move(component), "VEGAN"));
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}