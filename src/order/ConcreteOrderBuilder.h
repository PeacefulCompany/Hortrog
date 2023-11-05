#pragma once
#include "order/Modifier.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include <stdint.h>


class ConcreteOrderBuilder : public OrderBuilder {
public:
    void begin() {};
    bool addItem(const std::string& key) { return false; };
    std::string getResult();
    void begin(uint32_t tblId);
    bool addItem(const std::string& key, const std::string& customerName);
    bool addModifier(const std::string& key);
    Menu* getMenu();
    void setMenu(Menu* menu);
	OrderComposite* getOrder() { return this->order; };

private:
	uint32_t tblId_;
    Menu* menu;
    std::vector<std::unique_ptr<Order>> tempOrder;
    OrderComposite* order;
};