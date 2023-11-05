#pragma once
#include "order/Modifier.h"
#include "order/Order.h"
#include "order/OrderBuilder.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include <stdint.h>

class ConcreteOrderBuilder : public OrderBuilder {
public:
    ConcreteOrderBuilder(const Menu* menu);

    std::string getResult();
    void begin(uint32_t tblId) override;
    bool addItem(
        const std::string& key, const std::string& customerName) override;
    bool addModifier(const std::string& key) override;
    void setMenu(const Menu* menu) override { menu_ = menu; }
    const Menu* getMenu() const override { return menu_; }
    OrderComposite* getOrder() { return this->order; };

private:
    uint32_t tblId_;
    const Menu* menu_;
    std::vector<std::unique_ptr<Order>> tempOrder;
    OrderComposite* order;
};