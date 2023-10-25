#include <gtest/gtest.h>
#include <resource/ResourceManager.h>

struct DemoResource {
    bool loadFromFile(const std::string& path) { return path == "path"; }
};

TEST(ResourceTests, Test_LoadResource) {
    ResourceManager<DemoResource> manager;
    ASSERT_TRUE(manager.load(0, "path"));
    ASSERT_FALSE(manager.load(1, "not_a_path"));
    ASSERT_FALSE(manager.load(0, "path"));
}

TEST(ResourceTests, Test_GetResource) {
    ResourceManager<DemoResource> manager;
    manager.load(0, "path");

    ASSERT_NE(manager.get(0), nullptr);
    ASSERT_EQ(manager.get(1), nullptr);
}