#pragma once
#include "Builder.h"
#include "Order.h"
#include <memory>
class OrderBuilder : public Builder {
public:
    void build();
    OrderBuilder(int tablenumber);
    std::unique_ptr<Order> GetResult();
    void CreateTab(int tablenumber);
    void AddItem();

private:
    int tablenumber;
    std::unique_ptr<Order> newOrder;
};