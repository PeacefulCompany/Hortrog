#include "../src/order/OrderComposite.h"
#include "../src/order/OrderItem.h"
#include <gtest/gtest.h>

TEST(OrderComposite, PRICE) {
    auto orderItem = std::unique_ptr<Order>(new OrderItem("bonger", 2));
    orderItem->setPrice(1.0);
}