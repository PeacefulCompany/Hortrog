#pragma once
#include "order/Modifier.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"


class ConcreteOrderBuilder : public OrderBuilder {
public:
    std::string getResult();
    void begin();
    bool addItem(const std::string& key);
    bool addModifier(const std::string& key);
    Menu* getMenu();
    void setMenu(Menu* menu);

private:
    Menu* menu;
    std::vector<std::unique_ptr<Order>> tempOrder;
    OrderComposite* order;
};