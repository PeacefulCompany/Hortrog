#include "order/Receipt.h"
#include <gtest/gtest.h>

TEST(RECEIPT_TESTS, TO_STRING) {
    Receipt receipt;
    receipt.addPair(std::pair<std::string, double>("borger", 2.1));
    receipt.addPair(std::pair<std::string, double>("hortdog", 2.2));
    std::cout << receipt.toString();
    ASSERT_EQ(receipt.toString(), "borger : 2.100000\nhortdog : 2.200000\n");
}
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}