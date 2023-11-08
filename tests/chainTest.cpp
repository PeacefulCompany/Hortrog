#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderItem.h"
#include "subsystem/Chef/HeadChef.h"
#include "subsystem/Chef/Kitchen.h"
#include "subsystem/Chef/KitchenStaff.h"
#include "subsystem/Chef/NormalChef.h"
#include "subsystem/Meals/MealItem.h"
#include <gtest/gtest.h>

TEST(Kitchen, chainSetup) {
    Kitchen* kitchen = new Kitchen();

    KitchenStaff* headChef = new HeadChef(5, 5, kitchen, 1, "head_chef");

    KitchenStaff* chef1 = new NormalChef(4, 5, kitchen, 2, "fast_chef1");
    ((NormalChef*)chef1)->addCanPrepareItem("Grilled Salmon");
    ((NormalChef*)chef1)->addCanPrepareItem("Margherita Pizza");

    KitchenStaff* chef2 = new NormalChef(2, 5, kitchen, 3, "medium_chef1");
    ((NormalChef*)chef2)->addCanPrepareItem("Avocado Toast");
    ((NormalChef*)chef2)->addCanPrepareItem("Chicken Caesar Salad");

    KitchenStaff* chef3 = new NormalChef(5, 5, kitchen, 4, "slow_chef2");
    ((NormalChef*)chef3)->addCanPrepareItem("Vegetable Stir-Fry");
    ((NormalChef*)chef3)->addCanPrepareItem("Spinach and Feta Stuffed Chicken");

    KitchenStaff* chef4 = new NormalChef(4, 5, kitchen, 3, "slow_chef2");
    ((NormalChef*)chef4)->addCanPrepareItem("Black Bean Burger");
    ((NormalChef*)chef4)->addCanPrepareItem("Beef Tacos");

    KitchenStaff* chef5 = new NormalChef(3, 5, kitchen, 1, "barrista");
    ((NormalChef*)chef5)->addCanPrepareItem("Lemonade");
    ((NormalChef*)chef5)->addCanPrepareItem("Coconut Water");

    KitchenStaff* current = kitchen->getFirstChef();
    ASSERT_EQ(current->toString(), chef5->toString());
    current = current->getNextStaff();
    ASSERT_EQ(current->toString(), chef4->toString());
    current = current->getNextStaff();
    ASSERT_EQ(current->toString(), chef3->toString());
    current = current->getNextStaff();
    ASSERT_EQ(current->toString(), chef2->toString());
    current = current->getNextStaff();
    ASSERT_EQ(current->toString(), chef1->toString());
    current = current->getNextStaff();
    ASSERT_EQ(current->toString(), headChef->toString());
}

// TEST(Kitchen, orderHandle) {
//     Menu* menu = new Menu();
//     menu->loadFromFile("../assets/menu_items.json");
//     ConcreteOrderBuilder* orderBuilder = new ConcreteOrderBuilder(menu);

//     orderBuilder->begin(1);

//     orderBuilder->addItem("Beef Tacos", "john");
//     orderBuilder->addModifier("VEGAN");

//     orderBuilder->addItem("Lemonade", "john");

//     orderBuilder->addItem("Lemonade", "bob");

//     orderBuilder->addItem("Lemonade", "john");

//     std::string order = orderBuilder->getResult();
//     Order* o = orderBuilder->getOrder();
//     Kitchen* kitchen = new Kitchen();
//     kitchen->handleOrder(o);

//     for (int i = 0; i < 10; i++) {
//         kitchen->updateTime(1);
//     }

//     Meal* meal = kitchen->getOutgoingMeal();
//     Meal* meal2 = new Meal(o);
//     meal2->addItem(new MealItem("john", 3, "Lemonade", "none", "none"));
//     meal2->addItem(new MealItem("john", 4, "Beef Tacos", "none", "VEGAN"));
//     meal2->addItem(new MealItem("bob", 3, "Lemonade", "none", "none"));
//     ASSERT_EQ(meal->toString(), meal2->toString());
// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}