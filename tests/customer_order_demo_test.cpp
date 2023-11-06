#include <gtest/gtest.h>
#include <memory>
#include "demo/CustomerOrderDemo.h"

TEST(CustomerOrderDemoTests, INIT) {
    CustomerOrderDemo cod = CustomerOrderDemo();
    cod.init();
}