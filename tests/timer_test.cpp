#include "core/Timer.h"
#include <gtest/gtest.h>

TEST(TimerTests, TestCompleted) {
    Timer timer(10, true);
    ASSERT_TRUE(timer.isComplete());

    timer = Timer(10);
    ASSERT_FALSE(timer.isComplete());
    timer.update(10);
    ASSERT_TRUE(timer.isComplete());
}

TEST(TimerTests, TestTime) {
    Timer timer(10);
    ASSERT_EQ(timer.getTime(), 10);
}

TEST(TimerTests, TestUpdate) {
    Timer timer(10);
    timer.update(5);
    ASSERT_EQ(timer.getCurrent(), 5);
    timer.update(5);
    ASSERT_EQ(timer.getCurrent(), 10);
    timer.update(5);
    ASSERT_EQ(timer.getCurrent(), 15);
}

TEST(TimerTests, TestTick) {
    Timer timer(10);
    timer.update(22);
    timer.tick();
    ASSERT_EQ(timer.getCurrent(), 12);
    timer.tick();
    ASSERT_EQ(timer.getCurrent(), 2);
}

TEST(TimerTests, TestReset) {
    Timer timer(10);
    timer.update(10);
    timer.reset();
    ASSERT_EQ(timer.getCurrent(), 0);
}

TEST(TimerTests, TestProgress) {
    Timer timer(10);
    for (int i = 0; i < 10; i++) {
        ASSERT_NEAR(timer.getProgress(), 0.1f * i, 1e-5);
        timer.update(1.f);
    }
}