#include "menu/Menu.h"

#include <gtest/gtest.h>
#include <memory>

TEST(MenuTests, TestGetItem_Lemonade) {
    std::unique_ptr<MenuItem> item = std::make_unique<MenuItem>("Lemonade", 2.99, "Vegan", std::vector<std::string>{"Ice", "Sugar"});
	std::unique_ptr<MenuItem> item2 = std::make_unique<MenuItem>("Lemonade", 2.99, "Vegan", std::vector<std::string>{"Ice", "Sugar"});
	
    Menu m;
    std::cout << m.addMenuItem(item->getName(), std::move(item)) << std::endl;
    const MenuItem* i = m.getMenuItem("Lemonade");
    ASSERT_EQ(i->getName(), "Lemonade");
    ASSERT_EQ(i->getPrice(), 2.99);
    ASSERT_EQ(i->preparationMethod(), "Vegan");
}