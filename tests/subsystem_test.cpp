#include <gtest/gtest.h>
#include <subsystem/MyClass.h>

#include <string>

TEST(SubsystemTests, TestInteger) {
    MyClass<int> c(3);
    ASSERT_EQ(c.get(), 3);
}

TEST(SubsystemTests, TestString) {
    MyClass<std::string> c("test");
    ASSERT_EQ(c.get(), "test");
}
