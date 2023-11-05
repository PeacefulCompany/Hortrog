#include "menu/Menu.h"

#include <gtest/gtest.h>
#include <memory>

TEST(MenuTests, TestGetItem_Lemonade) {
    std::unique_ptr<MenuItem> item(new MenuItem("Lemonade", 2.99, "Vegan", {}));
    std::unique_ptr<MenuItem> item2(
        new MenuItem("Lemonade", 2.99, "Vegan", {}));

    Menu m;
    m.addMenuItem(item->getName(), std::move(item));
    m.addMenuItem(item->getName(), std::move(item2));
    const MenuItem* i = m.getMenuItem("Lemonade");
    ASSERT_EQ(i->getName(), "Lemonade");
    ASSERT_EQ(i->getPrice(), 2.99);
    ASSERT_EQ(i->preparationMethod(), "Vegan");
}