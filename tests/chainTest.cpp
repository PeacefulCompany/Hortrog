#include "../src/subsystem/Chef/NormalChef.h"
#include "../src/subsystem/Chef/HeadChef.h"
#include "../src/subsystem/Chef/KitchenStaff.h"
#include <gtest/gtest.h>
#include "../src/subsystem/Chef/Kitchen.h"
#include "order/ConcreteOrderBuilder.h"
#include "order/OrderBuilder.h"
#include "order/OrderItem.h"
#include "subsystem/Meals/MealItem.h"


TEST(Kitchen, chainSetup) {
    // Kitchen* kitchen = new Kitchen();
    NormalChef* normalChef = new NormalChef(4, 5, nullptr, 6, "bubble maker");
    HeadChef* headChef = new HeadChef(4, 5, nullptr, 6, "Head Chef");
    // KitchenStaff* kitchenStaff = new KitchenStaff();

    
    headChef->setNextStaff(normalChef);

    ASSERT_EQ(headChef->getNextStaff(), normalChef);
    
    delete normalChef;
    delete headChef;
}


TEST(Kitchen, orderHandle){
    Menu* menu = new Menu();
    menu->loadFromFile("menu_items.json");
    ConcreteOrderBuilder* orderBuilder = new ConcreteOrderBuilder(menu);

    orderBuilder->begin(1);
    orderBuilder->addItem("Beef Tacos", "john");
    orderBuilder->addModifier("VEGAN");
    orderBuilder->addItem("Lemonade", "john");

    std::string order = orderBuilder->getResult();
    Order * o = orderBuilder->getOrder();
    Kitchen* kitchen = new Kitchen();
    kitchen->handleOrder(o);

    for (int i = 0; i < 10; i++) {
        kitchen->updateTime(1);
    }

    Meal* meal = kitchen->getOutgoingMeal();
    Meal* meal2 = new Meal(o);
    meal2->addItem(new MealItem("john", 4, "Beef Tacos", "none", "VEGAN"));
    meal2->addItem(new MealItem("john", 3, "Lemonade", "none", "none"));
    ASSERT_EQ(meal->toString(), meal2->toString());
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}