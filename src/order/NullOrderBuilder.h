#pragma once

#include "OrderBuilder.h"
#include <vector>

#include "nlohmann/json.hpp"
#include "order/Order.h"
using json = nlohmann::json;

class NullOrderBuilder : public OrderBuilder {
public:
    void begin() override;
    bool addItem(const std::string& key) override;
    bool addModifier(const std::string& key) override;
    OrderComposite* getOrder() override { return nullptr; }
    Menu* getMenu() override { return nullptr; }
    void setMenu(Menu* menu) override {}

    inline const std::vector<json>& getResult() { return orders_; }

private:
    std::vector<json> orders_;
};