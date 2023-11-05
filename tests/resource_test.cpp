#include <gtest/gtest.h>
#include <resource/ResourceManager.h>

struct MockResource {
    int value = -1;
    bool loadFromFile(const std::string& path, int v = 2) {
        if (path != "path") return false;
        value = v;
        return true;
    }
};

TEST(ResourceTests, Test_LoadResource) {
    ResourceManager<MockResource> manager;
    ASSERT_TRUE(manager.load(0, "path"));
    ASSERT_FALSE(manager.load(1, "not_a_path"));
    ASSERT_FALSE(manager.load(0, "path"));
}

TEST(ResourceTests, Test_GetResource) {
    ResourceManager<MockResource> manager;
    manager.load(0, "path", 3);

    ASSERT_NE(manager.get(0), nullptr);
    ASSERT_EQ(manager.get(1), nullptr);
    ASSERT_EQ(manager.get(0)->value, 3);
}