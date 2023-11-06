#include <gtest/gtest.h>
#include <memory>
#include "demo/CustomerOrderDemo.h"

TEST(CustomerOrderDemoTests, INIT) {
    CustomerOrderDemo cod = CustomerOrderDemo();
    cod.init();
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}