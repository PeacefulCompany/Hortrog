#include "subsystem/Meals/MealItem.h"
#include <gtest/gtest.h>

TEST(MealItemTests, TestGetCustomer) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_EQ(mealItem->getCustomer(), "Kivashin");
}

TEST(MealItemTests, TestGetQuality) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_FLOAT_EQ(mealItem->getQuality(), 9.99);
}

TEST(MealItemTests, TestGetDiet) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_EQ(mealItem->getDiet(), "Wine");
}

TEST(MealItemTests, TesGetModifier) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_EQ(mealItem->getMod(), "no coconut");
}

TEST(MealItemTests, TestGetFood) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_EQ(mealItem->getFood(), "Beef Taco");
}

TEST(MealItemTests, TestToString) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_EQ(mealItem->toString(),
        "{item: Beef Taco, quality: 9.990000, diet: Wine, modifier: no "
        "coconut}");
}

TEST(MealItemTests, TestIsEqual) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    MealItem* mealItem2 =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_TRUE(mealItem->isEqual(mealItem2));
}

TEST(MealItemTests, TestIsReady) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    ASSERT_FALSE(mealItem->isReady());
}

TEST(MealItemTests, TestSetReady) {
    MealItem* mealItem =
        new MealItem("Kivashin", 9.99, "Beef Taco", "Wine", "no coconut");
    mealItem->setReady(true);
    ASSERT_TRUE(mealItem->isReady());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
