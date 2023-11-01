#include <gtest/gtest.h>
#include <multiply/multiply.h>

TEST(OrderComposite, TestIntegerOne_One) {
    const auto expected = 1;
    const auto actual = multiply(1, 1);
    ASSERT_EQ(expected, actual);
}
