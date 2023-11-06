#include "menu/Menu.h"
#include <gtest/gtest.h>

TEST(MenuTests, TestGetItem_Lemonade) {
    Item item = Item("Lemonade", 2.99, "Vegan");
    Menu* m = new Menu();
    m->addItem(item.getName(), item);
    Item item2 = m->getItem("Lemonade");
    ASSERT_EQ(item2.getName(), "Lemonade");
    ASSERT_EQ(item2.getPrice(), 2.99);
    ASSERT_EQ(item2.getRestrictions(), "Vegan");
}