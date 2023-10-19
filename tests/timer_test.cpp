#include "core/Timer.h"
#include <gtest/gtest.h>

TEST(TimerTests, TestCompleted) {
    Timer timer(10, true);
    ASSERT_TRUE(timer.expired());

    timer = Timer(10);
    ASSERT_FALSE(timer.expired());
    timer.update(10);
    ASSERT_TRUE(timer.expired());
}

TEST(TimerTests, TestTime) {
    Timer timer(10);
    ASSERT_EQ(timer.duration(), 10);
}

TEST(TimerTests, TestUpdate) {
    Timer timer(10);
    timer.update(5);
    ASSERT_EQ(timer.current(), 5);
    timer.update(5);
    ASSERT_EQ(timer.current(), 10);
    timer.update(5);
    ASSERT_EQ(timer.current(), 15);
}

TEST(TimerTests, TestTick) {
    Timer timer(10);
    timer.update(22);
    timer.tick();
    ASSERT_EQ(timer.current(), 12);
    timer.tick();
    ASSERT_EQ(timer.current(), 2);
}

TEST(TimerTests, TestReset) {
    Timer timer(10);
    timer.update(10);
    timer.reset();
    ASSERT_EQ(timer.current(), 0);
}

TEST(TimerTests, TestProgress) {
    Timer timer(10);
    for (int i = 0; i < 10; i++) {
        ASSERT_NEAR(timer.progress(), 0.1f * i, 1e-5);
        timer.update(1.f);
    }
}