#pragma once
#include "menu/Menu.h"
#include "order/Modifier.h"
#include "order/Order.h"
#include "order/OrderComposite.h"
#include "order/OrderItem.h"
#include <sstream>
#include <string>
#include <vector>

class OrderBuilder {
public:
    virtual ~OrderBuilder(){};
    virtual void begin(uint32_t tableId) = 0;
    virtual bool addItem(
        const std::string& key, const std::string& customer) = 0;
    virtual bool addModifier(const std::string& key) = 0;
    virtual void setMenu(const Menu* menu) = 0;
    virtual const Menu* getMenu() const = 0;

    virtual OrderComposite* getOrder() = 0;

};