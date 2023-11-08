#include "menu/Menu.h"

#include <gtest/gtest.h>
#include <memory>

TEST(MenuTests, TestAddItem) {
    Menu m;

    const std::string name = "lemonade";
    const std::vector<std::string> mods = {};

    auto item = std::make_unique<MenuItem>(name, 2.99, "vegan", mods);
    ASSERT_TRUE(m.addMenuItem(name, std::move(item)));
}

TEST(MenuTests, TestGetItem) {
    const std::string name = "lemonade";
    const std::vector<std::string> mods = {"ice", "sugar"};

    Menu m;
    m.addMenuItem(name, std::make_unique<MenuItem>(name, 2.99, "vegan", mods));

    const MenuItem* i = m.getMenuItem(name);
    ASSERT_NE(i, nullptr);
    ASSERT_EQ(i->getName(), name);
    ASSERT_EQ(i->preparationMethod(), "vegan");
    ASSERT_EQ(i->getPrice(), 2.99);

    std::vector<std::string> supported = i->supportedModifiers();
    ASSERT_EQ(supported.size(), mods.size());
    for (size_t i = 0; i < supported.size(); i++) {
        ASSERT_EQ(supported[i], mods[i]);
    }
}