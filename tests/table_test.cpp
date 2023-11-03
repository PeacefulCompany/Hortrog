#include <gtest/gtest.h>

#include <floor/Customer.h>
#include <floor/TableComponent.h>

TEST(TableTests, TestTableComponent_Getters) {
    TableComponent table(1, 2);
    ASSERT_EQ(table.id(), 1);
    ASSERT_EQ(table.capacity(), 2);
    ASSERT_TRUE(table.isEmpty());
}

TEST(TableTests, TestTableComponent_AddCustomer) {
    Customer c1("alice");
    Customer c2("bob");
    Customer c3("charlie");

    TableComponent table(1, 2);

    ASSERT_TRUE(table.seatCustomer(&c1));
    ASSERT_TRUE(table.seatCustomer(&c2));
    ASSERT_FALSE(table.seatCustomer(&c3));
}

TEST(TableTests, TestTableComponent_RemoveCustomer) {
    Customer c1("alice");

    TableComponent table(1, 2);

    ASSERT_TRUE(table.seatCustomer(&c1));
    ASSERT_TRUE(table.removeCustomer(&c1));
    ASSERT_FALSE(table.removeCustomer(&c1));
}

TEST(TableTests, TestTableComponent_MergeTable) {
    TableComponent table(1, 2);
    ASSERT_FALSE(table.merge(new TableComponent(1, 2)));
}

TEST(TableTests, TestTableComponent_SplitTable) {
    TableComponent table(1, 2);
    std::vector<TableComponent*> split = table.split();
    ASSERT_EQ(split.size(), 1);
    ASSERT_EQ(split[0], &table);
}